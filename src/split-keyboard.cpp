#include "split-keyboard.h"

SplitKeyboard::SplitKeyboard()
{
    keyboardLeft = lv_obj_create(lv_screen_active());
    keyboardRight = lv_obj_create(lv_screen_active());
    swapSideButtonLeft = lv_button_create(keyboardLeft);
    swapSideButtonRight = lv_button_create(keyboardRight);
}

void SplitKeyboard::Destroy()
{
    lv_obj_del(keyboardLeft);
    
}