/*******************************************************************************
 * @file         : AlertTypesConstants.h
 * @author       : Abhipsa Panda
 * @brief        : Defines constants information used for alert handling
********************************************************************************/


#ifndef ALERT_TYPES_CONSTANTS_H
#define ALERT_TYPES_CONSTANTS_H


#include <vector>
#include <string>


enum enCoolingType
{
   COOLING_TYPE_UNKNOWN,
   COOLING_TYPE_PASSIVE,
   COOLING_TYPE_HI_ACTIVE,
   COOLING_TYPE_MED_ACTIVE
};


enum enBreachType
{
   BREACH_TYPE_NORMAL,
   BREACH_TYPE_TOO_LOW,
   BREACH_TYPE_TOO_HIGH
};


class CoolingTypeInfo;
class BatteryInfo;


typedef ::std::vector<CoolingTypeInfo> CoolingTypesInfo;

typedef ::std::vector<BatteryInfo> BatteriesInfo;


#endif /* ALERT_TYPES_CONSTANTS_H */