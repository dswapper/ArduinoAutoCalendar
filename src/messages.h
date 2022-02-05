#include <Arduino.h>
#include "config.h"
#include "defs.h"

#ifndef AUTOCALENDAR_MESSAGES_H
#define AUTOCALENDAR_MESSAGES_H



String welcome_msg = String(String("The Auto-Calendar have started successfully \n") + String("Current date is: ")
        + toStringCurrentTime());

#endif //AUTOCALENDAR_MESSAGES_H
