/********************************************************************************
 * @file         : typewise-alert.h
 * @author       : 
 * @brief        : Implements the alert notification handling
 ********************************************************************************/


#ifndef TYPEWISE_ALERT_H
#define TYPEWISE_ALERT_H

#include "AlertSystem.h"


enBreachType checkAndAlertWithoutController(int id, int temperatureInC);
enBreachType checkAndAlertWithController(int id, int temperatureInC);


#endif /* TYPEWISE_ALERT_H */