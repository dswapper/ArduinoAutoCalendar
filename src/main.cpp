/*
 * GitHub: github.com/dswapper
 * Project: AutoCalendar (ВСОШ Технология 2022)
 * Author: DrSwapper
 */

#include <Arduino.h>
#include <RTClib.h>

#include "config.h"
#include "messages.h"
#include "defs.h"

void setup() {
    Serial.begin(115200);
    for (auto pin : output_pins){
        pinMode(pin, OUTPUT);
    }
    for (auto stepper : steppers){
        stepper->setSpeed(STEPS_28BYJ48_SPEED);
    }

    Serial.println(welcome_msg);

    if (!rtc.begin()) {
        Serial.println("Couldn't find RTC :< \n Please install it");
        delay(10000);
        while (true){
            delay(1000);
            if (rtc.begin()) {break;}
        }
    }
    if (!rtc.isrunning()) {
        Serial.println("RTC is NOT running, setting up time");
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }
}

void loop() {

}