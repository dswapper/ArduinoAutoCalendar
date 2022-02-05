#include <Stepper.h>

#ifndef AUTOCALENDAR_CONFIG_H
#define AUTOCALENDAR_CONFIG_H

#define STEPS_28BYJ48       64 // 5.625 deg per step
#define STEPS_28BYJ48_SPEED 32

#define DAY_PIN1            1
#define DAY_PIN2            1
#define DOW_PIN1            1 // DOW = Day of Week
#define DOW_PIN2            1
#define MONTH_PIN1          1
#define MONTH_PIN2          1

Stepper day_stepper(STEPS_28BYJ48, DAY_PIN1, DAY_PIN2);
Stepper dow_stepper(STEPS_28BYJ48, DOW_PIN1, DOW_PIN2);
Stepper month_stepper(STEPS_28BYJ48, MONTH_PIN1, MONTH_PIN2);
RTC_DS1307 rtc;

Stepper* steppers[3]{
        &day_stepper,
        &dow_stepper,
        &month_stepper
};

int8_t output_pins[] = {DOW_PIN1, DOW_PIN2, DAY_PIN1, DAY_PIN2, MONTH_PIN1, MONTH_PIN2};


#define DAY_GEAR_RATIO
#define DOW_GEAR_RATIO
#define MONTH_GEAR_RATIO

#define STEPS_IN_DAY
#define STEPS_IN_DOW
#define STEPS_IN_MONTH


#endif //AUTOCALENDAR_CONFIG_H
