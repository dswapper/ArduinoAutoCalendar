#include <Arduino.h>
#include "config.h"

#ifndef AUTOCALENDAR_DEFS_H
#define AUTOCALENDAR_DEFS_H

// TODO: считывание с RTC
String toStringCurrentTime() {
    if (!DEBUG) {
        DateTime current_time = rtc.now();
        return {String(current_time.day()) + '.' +
                String(current_time.month()) + ' ' +
                String(daysOfTheWeek[current_time.dayOfTheWeek()])};
    }
    else {
        return {"13.02.2004 Friday"};
    }
}


// TODO: полный прокрут всех кругов раз в заданный период (!)
void setDay(uint16_t day) {
    // TODO: дни скипаются не равномерно(


    steppers[1]->step(STEPS_IN_DOW);
}

void nextMonth(){
    steppers[3]->step(STEPS_IN_MONTH);
}

#endif //AUTOCALENDAR_DEFS_H
