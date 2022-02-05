#include <Arduino.h>
#include "config.h"

#ifndef AUTOCALENDAR_DEFS_H
#define AUTOCALENDAR_DEFS_H

String daysOfTheWeek[7] = {"Sunday", "Monday", "Tuesday", "Wednesday",
                           "Thursday", "Friday", "Saturday"};

String toStringCurrentTime() {
/*
    DateTime current_time = rtc.now();
    return {String(current_time.day()) + '.' +
            String(current_time.month()) + ' ' +
            String(daysOfTheWeek[current_time.dayOfTheWeek()])};
*/

    return {"13.02.2004 Friday"};
}

#endif //AUTOCALENDAR_DEFS_H
