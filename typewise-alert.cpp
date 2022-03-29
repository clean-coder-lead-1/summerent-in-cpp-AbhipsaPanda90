/********************************************************************************
 * @file         : typewise-alert.h
 * @author       : 
 * @brief        : Implements the alert notification handling
 ********************************************************************************/

#include "typewise-alert.h"
#include <stdio.h>


enBreachType checkAndAlertWithoutController(int id, double temperatureInC)
{
   enBreachType bType = BREACH_TYPE_NORMAL;
   AlertSystem system;
   printf("checkAndAlertWithoutController id = %d", id);
   printf("checkAndAlertWithoutController temp = %d", temperatureInC);
   system.checkBreachAndAlert(id, temperatureInC);
   printf("checkAndAlertWithoutController = %d", bType);
   return bType;
}


enBreachType checkAndAlertWithController(int id, double temperatureInC)
{
   enBreachType bType = BREACH_TYPE_NORMAL;
   AlertSystem system;
   system.configureSystemController("DISPLAY");
   printf("checkAndAlertWithController id = %d", id);
   printf("checkAndAlertWithController temp = %d", temperatureInC);
   system.checkBreachAndAlert(id, temperatureInC);
   printf("checkAndAlertWithController = %d", bType);
   return bType;
}