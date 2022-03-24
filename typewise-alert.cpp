/********************************************************************************
 * @file         : typewise-alert.h
 * @author       : 
 * @brief        : Implements the alert notification handling
 ********************************************************************************/

#include "typewise-alert.h"


enBreachType checkAndAlertWithoutController(int id, double temperatureInC)
{
   enBreachType bType = BREACH_TYPE_NORMAL;
   AlertSystem system;
   system.checkBreachAndAlert(id, temperatureInC);
   return bType;
}


enBreachType checkAndAlertWithController(int id, double temperatureInC)
{
   enBreachType bType = BREACH_TYPE_NORMAL;
   AlertSystem system;
   system.configureSystemController("DISPLAY");
   system.checkBreachAndAlert(id, temperatureInC);
   return bType;
}