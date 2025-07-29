#pragma once
#include <lvgl.h>
#include <eventpp/hetereventdispatcher.h>
//TODO: use a simple callback function pointer instead of eventpp

enum class SplitKeyboardState {
    Left,
    Right,
    Hidden
};

class SplitKeyboard {
public:
    SplitKeyboard();
    void Destroy();
    void Toggle();

private:
    void swapSide();
    //void swapSideButtonPressed(lv_event_t*);
    SplitKeyboardState currentState;
    lv_obj_t * keyboardLeft;
    lv_obj_t * keyboardRight;
    lv_obj_t * swapSideButtonLeft;
    lv_obj_t * swapSideButtonRight;
};