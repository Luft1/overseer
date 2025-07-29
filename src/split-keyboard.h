#pragma once
#include <lvgl.h>
#include <eventpp/hetereventdispatcher.h>
#include "Events.h"

enum class KeyboardState {
    Left,
    Right,
    Hidden
};

class SplitKeyboard {
public:
    using KeyboardEventDispatcher = eventpp::HeterEventDispatcher<Event, void(char)>;
    SplitKeyboard();
    void Destroy();
    KeyboardEventDispatcher& getDispatcher() {
        return keyboardEventDispatcher;
    };
    void Toggle();

private:
    void swapSide();
    //void swapSideButtonPressed(lv_event_t*);
    KeyboardState * currentState;
    lv_obj_t * keyboardLeft;
    lv_obj_t * keyboardRight;
    lv_obj_t * swapSideButtonLeft;
    lv_obj_t * swapSideButtonRight;
    KeyboardEventDispatcher keyboardEventDispatcher;
};