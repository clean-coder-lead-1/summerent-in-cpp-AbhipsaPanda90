/********************************************************************************
 * @file         : typewise-alert.h
 * @author       : 
 * @brief        : Implements the alert notification handling
 ********************************************************************************/

#include "typewise-alert.h"
#include <stdio.h>


enBreachType checkAndAlertWithoutController(int id, int temperatureInC)
{
   enBreachType bType = BREACH_TYPE_NORMAL;
   AlertSystem system;
   printf("checkAndAlertWithoutController id = %d \n", id);
   printf("checkAndAlertWithoutController temp = %d \n", temperatureInC);
   bType = system.checkBreachAndAlert(id, temperatureInC);
   printf("checkAndAlertWithoutController = %d \n", bType);
   return bType;
}


enBreachType checkAndAlertWithController(int id, int temperatureInC)
{
   enBreachType bType = BREACH_TYPE_NORMAL;
   AlertSystem system;
   system.configureSystemController("DISPLAY");
   printf("checkAndAlertWithController id = %d \n", id);
   printf("checkAndAlertWithController temp = %d \n", temperatureInC);
   bType = system.checkBreachAndAlert(id, temperatureInC);
   printf("checkAndAlertWithController = %d \n", bType);
   return bType;
}