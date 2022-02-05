#include <Stepper.h>

#ifndef AUTOCALENDAR_CONFIG_H
#define AUTOCALENDAR_CONFIG_H

#define empt 1
#define DEBUG true

#define STEPS_28BYJ48       64 // 5.625 deg per step
#define STEPS_28BYJ48_SPEED 32

#define DAY_PIN1            empt
#define DAY_PIN2            empt
#define DOW_PIN1            empt // DOW = Day of Week
#define DOW_PIN2            empt
#define MONTH_PIN1          empt
#define MONTH_PIN2          empt

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

#define DAY_GEAR_RATIO empt
#define DOW_GEAR_RATIO empt
#define MONTH_GEAR_RATIO empt

#define STEPS_IN_DAY empt
#define STEPS_IN_DOW empt
#define STEPS_IN_MONTH empt

DateTime current_time;
uint16_t current_day;
uint16_t current_month;
uint16_t previous_day;
uint16_t previous_month;
uint32_t previous_time;


byte EEPROM_Day;
byte EEPROM_Month;
byte EEMEM EEPROM_Day_addr;
byte EEMEM EEPROM_Month_addr;


const PROGMEM uint8_t days_in_month[]  = {
        0, 31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31};
const PROGMEM char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday",
                                  "Thursday", "Friday", "Saturday"};
// TODO: Високосный год чеееек

#endif //AUTOCALENDAR_CONFIG_H
