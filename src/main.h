#pragma once
#include <LilyGoLib.h>
#include <LV_Helper.h>
#include "split-keyboard.h"

class Main {
public:
    Main();
    void loop();
private:
SplitKeyboard * keyboard;
lv_obj_t * textBox;
lv_obj_t * toggleKeyboardButton;
void handleKeyPress(char);

};