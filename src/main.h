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
};