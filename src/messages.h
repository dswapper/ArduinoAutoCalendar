#include <Arduino.h>
#include "config.h"
#include "defs.h"

#ifndef AUTOCALENDAR_MESSAGES_H
#define AUTOCALENDAR_MESSAGES_H

String welcome_msg = String("The Auto-Calendar have started successfully \n") + String("Current date is: ")
        + toStringCurrentTime();

String next_day_msg = "New Day!!!";
String next_month_msg = "New Month!!!";
String config_menu_enter_msg = "You've entered config menu:"; // TODO: инструкция
String config_menu_exit_msg = "Configuration finished, settings saved";

#endif //AUTOCALENDAR_MESSAGES_H
