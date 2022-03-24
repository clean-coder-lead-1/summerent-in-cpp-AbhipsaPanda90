/********************************************************************************
 * @file         : typewise-alert.h
 * @author       : 
 * @brief        : Implements the alert notification handling
 ********************************************************************************/

#include "typewise-alert.h"


const enBreachType checkAndAlertWithoutController(int id, double temperatureInC) const
{
   const enBreachType bType = BREACH_TYPE_NORMAL;
   AlertSystem system;
   system.checkBreachAndAlert(id, temperatureInC);
   return bType;
}


const enBreachType checkAndAlertWithController(int id, double temperatureInC) const
{
   const enBreachType bType = BREACH_TYPE_NORMAL;
   AlertSystem system;
   system.configureSystemController("DISPLAY");
   system.checkBreachAndAlert(id, temperatureInC);
   return bType;
}