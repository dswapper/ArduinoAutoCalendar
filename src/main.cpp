/*
 * GitHub: github.com/dswapper
 * Project: AutoCalendar (ВСОШ Технология 2022)
 * Author: DrSwapper
 */

#include <Arduino.h>
// TODO: RTC Alarms на 12:00 (я гений)
#include <RTClib.h>

#include "config.h"
#include "messages.h"
#include "defs.h"

uint32_t update_timing = 15 * 60000; // 15 minutes


void getCurrentTime(){
    if(!DEBUG) {
        current_time = rtc.now();
    }
    else{
        current_time = DateTime(2004, 2, 13, 2, 15, 50);
    }
    current_day = current_time.day();
    current_month = current_time.month();
}

void setup() {
    Serial.begin(115200);
    for (auto pin : output_pins){
        pinMode(pin, OUTPUT);
    }
    for (auto stepper : steppers){
        stepper->setSpeed(STEPS_28BYJ48_SPEED);
    }

    Serial.println(welcome_msg);
    if (!DEBUG) {
        if (!rtc.begin()) {
            Serial.println("Couldn't find RTC :< \n Please install it");
            delay(10000);
            while (true) {
                delay(1000);
                if (rtc.begin()) { break; }
            }
        }
        if (!rtc.isrunning()) {
            Serial.println("RTC is NOT running, setting up time");
            rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
        }
    }

    getCurrentTime();
    previous_day = current_day;
    previous_month = current_month;
    previous_time = millis();
}

void loop() {
    if (millis() - previous_time > update_timing) {
        getCurrentTime();

        if (abs(current_month - previous_month) != 0) {
            Serial.println(next_month_msg);
            nextMonth();
            previous_month = current_month;
        }
        else if (abs(current_day - previous_day) != 0) {
            Serial.println(next_day_msg);
            setDay(current_day);
            previous_day = current_day;
        }
    }

    String input_string;
    if (Serial.available() > 0){
        input_string = Serial.readString();
    }

    previous_time = millis();
}

void configure_menu(){

}