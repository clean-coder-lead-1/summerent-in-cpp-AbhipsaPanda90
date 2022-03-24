/********************************************************************************
 * @file         : typewise-alert.h
 * @author       : 
 * @brief        : Implements the alert notification handling
 ********************************************************************************/


#ifndef TYPEWISE_ALERT_H
#define TYPEWISE_ALERT_H

#include "AlertSystem.h"


const enBreachType checkAndAlertWithoutController(int id, double temperatureInC) const;
const enBreachType checkAndAlertWithController(int id, double temperatureInC) const;


#endif /* TYPEWISE_ALERT_H */