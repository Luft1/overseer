#include "main.h"

Main::Main() {

    keyboard = new SplitKeyboard();
    Serial.begin(115200);

    instance.begin();
    beginLvglHelper(instance);
    instance.setBrightness(DEVICE_MAX_BRIGHTNESS_LEVEL);

    textBox = lv_label_create(lv_screen_active());
    lv_obj_align(textBox, LV_ALIGN_TOP_MID, 0, 0);

    toggleKeyboardButton = lv_button_create(lv_screen_active());
    lv_obj_set_size(toggleKeyboardButton, 40, 40);
    lv_obj_align(toggleKeyboardButton, LV_ALIGN_TOP_RIGHT, -10, 10);
    lv_obj_add_event_cb(toggleKeyboardButton, +[](lv_event_t* event) {
        SplitKeyboard * keyboard = static_cast<SplitKeyboard*>(lv_event_get_user_data(event));
        keyboard->Toggle();
    }, LV_EVENT_CLICKED, this->keyboard);

    eventDispatcher.appendListener(Event::KeyPressed, [this](char key) { handleKeyPress(key); });
}

void Main::loop() {
    lv_timer_handler();
    delay(2);
}

void Main::handleKeyPress(char key) {
    lv_label_set_text(textBox, lv_label_get_text(textBox) + key);
}

static Main * mainInstance;

void setup()
{
    mainInstance = new Main();
}


void loop()
{
    mainInstance->loop();
}
