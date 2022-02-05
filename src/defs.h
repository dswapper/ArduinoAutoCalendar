#include <Arduino.h>
#include "config.h"

#ifndef AUTOCALENDAR_DEFS_H
#define AUTOCALENDAR_DEFS_H

void setMonth(uint16_t month);
void setDay(uint16_t day);
String toStringCurrentTime();


String toStringCurrentTime() {
    return {String(current_day) + '.' +
            String(current_month) + ' ' +
            String(daysOfTheWeek[current_time.dayOfTheWeek()])};
}

// TODO: полный прокрут всех кругов раз в заданный период (!)
void setDay(uint16_t day) {
    // TODO: дни скипаются не равномерно(
    uint8_t steps = current_day - previous_day;

    if (steps < 0){
        steps = days_in_month[current_month] + current_day - previous_day;
        setMonth(current_month);
    }

    for (int i = 0; i < steps; i++) {
        steppers[1]->step(STEPS_IN_DOW);
        steppers[0]->step(STEPS_IN_DAY);
    }


    EEPROM_Day = current_day;
    EEPROM.update(EEPROM_Day_addr, EEPROM_Day);
}

void setMonth(uint16_t month){
    uint8_t steps = current_month - previous_month;

    if (steps < 0){
        steps = 12 + current_month - previous_month;
    }

    for (int i = 0; i < steps; i++) {
        steppers[3]->step(STEPS_IN_MONTH);
    }
    EEPROM_Month = current_month;
    EEPROM.update(EEPROM_Month_addr, EEPROM_Day_addr);
}

#endif //AUTOCALENDAR_DEFS_H
