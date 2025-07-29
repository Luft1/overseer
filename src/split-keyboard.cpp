#include "split-keyboard.h"
#include "lv-utility.h"
//TODO: use a simple callback function pointer instead of eventpp

void SplitKeyboard::Toggle() {
    if (currentState == SplitKeyboardState::Hidden) {
        ShowObject(keyboardLeft);
        HideObject(keyboardRight);
        currentState = SplitKeyboardState::Left; // Default to left side
    } else {
        HideObject(keyboardLeft);
        HideObject(keyboardRight);
        currentState = SplitKeyboardState::Hidden;
    }
};

static void OnKeyPressed(lv_event_t * event) {
    lv_obj_t * buttonMatrix = static_cast<lv_obj_t*>(lv_event_get_target(event));
    const char * label = lv_buttonmatrix_get_button_text(buttonMatrix, lv_buttonmatrix_get_selected_button(buttonMatrix));
    if (label && label[0] != '\0') {
        eventDispatcher->dispatch(Event::KeyPressed, label[0]);
    }
};

SplitKeyboard::SplitKeyboard()
{
    keyboardLeft = lv_buttonmatrix_create(lv_screen_active());
    lv_obj_align(keyboardLeft, LV_ALIGN_BOTTOM_MID, 0, 0);
    lv_obj_set_size(keyboardLeft, 240, 240 * 0.75);
    keyboardRight = lv_buttonmatrix_create(lv_screen_active());
    lv_obj_align(keyboardRight, LV_ALIGN_BOTTOM_MID, 0, 0);
    lv_obj_set_size(keyboardRight, 240, 240 * 0.75);
    static const char * leftButtons[] = {
      "a", "b", "c", "d", "\n", "e", "f", "g", "h", "\n", "i", "j", "k", " ", ""
    };
    static const char * rightButtons[] = {
      "l", "m", "n", "o", "\n", "p", "q", "r", "s", "\n", "t", "u", "v", "w", ""
    };
    lv_buttonmatrix_set_map(keyboardLeft, leftButtons);
    lv_buttonmatrix_set_map(keyboardRight, rightButtons);
    lv_obj_add_event_cb(keyboardLeft, OnKeyPressed, LV_EVENT_VALUE_CHANGED, this);
    
    // Create swap button on the left keyboard
    swapSideButtonLeft = lv_button_create(keyboardLeft);
    lv_obj_align(swapSideButtonLeft, LV_ALIGN_BOTTOM_RIGHT, 0, 0);
    lv_obj_add_event_cb(swapSideButtonLeft, +[](lv_event_t* e) { static_cast<SplitKeyboard*>(lv_event_get_user_data(e))->swapSide(); }, LV_EVENT_PRESSED, this);
    
    // Create swap button on the right keyboard
    swapSideButtonRight = lv_button_create(keyboardRight);
    lv_obj_align(swapSideButtonRight, LV_ALIGN_BOTTOM_LEFT, 0, 0);
    lv_obj_add_event_cb(swapSideButtonRight, +[](lv_event_t* e) { static_cast<SplitKeyboard*>(lv_event_get_user_data(e))->swapSide(); }, LV_EVENT_PRESSED, this);
 
    // Fix: ToggleVisibility should be called with one keyboard at a time.
    // The following two lines would make them both visible or both hidden, defeating the purpose.
    // I am assuming you want them both hidden initially.
    HideObject(keyboardLeft);
    HideObject(keyboardRight);

    currentState = SplitKeyboardState::Hidden;
};

void SplitKeyboard::Destroy()
{
    lv_obj_del(keyboardLeft);
    lv_obj_del(keyboardRight);
    // No need to delete swapSideButtonLeft/Right as they are children of keyboardLeft/Right
};

void SplitKeyboard::swapSide()
{
    switch(currentState) {
        case SplitKeyboardState::Left:
            HideObject(keyboardLeft);
            ShowObject(keyboardRight);
            currentState = SplitKeyboardState::Right;
            break;
        case SplitKeyboardState::Right:
            HideObject(keyboardRight);
            ShowObject(keyboardLeft);
            currentState = SplitKeyboardState::Left;
            break;
        default:
            break;
    }
};