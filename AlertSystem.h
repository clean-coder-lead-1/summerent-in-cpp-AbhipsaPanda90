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
      enBreachType checkBreachAndAlert(const int id, const double currentTemp);

   private:
      void initializeBatteriesInfo();
      void initializeCoolingTypesInfo();
      BatteriesInfo getBatteriesInfo();
      CoolingTypesInfo getCoolingTypesInfo();
      BatteryInfo* getBatteryInfo(const int id);
      CoolingTypeInfo* getCoolingTypeInfo(const enCoolingType type);
      enCoolingType getCoolingTypeForBattery(const int id) const;
      int getMinTempLimitForCoolingType(const enCoolingType type) const;
      int getMaxTempLimitForCoolingType(const enCoolingType type) const;
      enBreachType inferBreachForCoolingType(const enCoolingType type, const double currentTemp);
      void informBreachInfoToController(const enBreachType bType);

      ::std::string _controller;
      BatteriesInfo _batteriesInfo;
      CoolingTypesInfo _coolingTypesInfo;
};


#endif // ALERT_SYSTEM_H