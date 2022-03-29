/*******************************************************************************
 * @file         : AlertSystem.h
 * @author       : Abhipsa Panda
 * @brief        : Implements the system information used for alert handling
********************************************************************************/


#ifndef ALERT_SYSTEM_H
#define ALERT_SYSTEM_H


#include "AlertTypesConstants.h"


class AlertSystem
{
   public:
      AlertSystem();
      virtual ~AlertSystem();

      void configureSystemController(::std::string controller);
      enBreachType checkBreachAndAlert(int id, int currentTemp);

   private:
      void initializeBatteriesInfo();
      void initializeCoolingTypesInfo();
      BatteriesInfo getBatteriesInfo();
      CoolingTypesInfo getCoolingTypesInfo();
      BatteryInfo* getBatteryInfo(int id);
      CoolingTypeInfo* getCoolingTypeInfo(enCoolingType type);
      enCoolingType getCoolingTypeForBattery(int id);
      int getMinTempLimitForCoolingType(enCoolingType type);
      int getMaxTempLimitForCoolingType(enCoolingType type);
      enBreachType inferBreachForCoolingType(enCoolingType type, int currentTemp);
      void informBreachInfoToController(enBreachType bType);

      ::std::string _controller;
      BatteriesInfo _batteriesInfo;
      CoolingTypesInfo _coolingTypesInfo;
};


#endif // ALERT_SYSTEM_H