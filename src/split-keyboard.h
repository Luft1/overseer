#pragma once
#include <lvgl.h>
class SplitKeyboard {
public:
    SplitKeyboard();
    void Destroy();
    void Enable();
    void Disable();

private:
lv_obj_t * keyboardLeft;
lv_obj_t * keyboardRight;
lv_obj_t * swapSideButtonLeft;
lv_obj_t * swapSideButtonRight;
};