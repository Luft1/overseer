#include "main.h"

Main::Main() {
    Serial.begin(115200);
    instance.begin();
    beginLvglHelper(instance);
    instance.setBrightness(DEVICE_MAX_BRIGHTNESS_LEVEL);
}

void Main::loop() {
    lv_timer_handler();
    delay(2);
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
