/*******************************************************************************
 * @file         : AlertSystem.cpp
 * @author       : Abhipsa Panda
 * @brief        : Implements the system information used for alert handling
********************************************************************************/


#include "AlertSystem.h"
#include "AlertTypesInfo.h"
#include <stdio.h>
#include <iostream>
#include <iterator>

using namespace std;


AlertSystem::AlertSystem(): _controller("")
{
   _batteriesInfo.clear();
   _coolingTypesInfo.clear();
   initializeBatteriesInfo();
   initializeCoolingTypesInfo();
}


AlertSystem::~AlertSystem()
{
   _batteriesInfo.clear();
   _coolingTypesInfo.clear();
   _controller = "";
}


void AlertSystem::configureSystemController(::std::string controller)
{
   _controller = controller;
}


#define CONFIGURE_BATTERIES_INFO

BatteriesInfo AlertSystem::getBatteriesInfo()
{
#include "AlertSystemConfigInfo.dat"
}

#undef CONFIGURE_BATTERIES_INFO


#define CONFIGURE_COOLING_TYPES_INFO

CoolingTypesInfo AlertSystem::getCoolingTypesInfo()
{
#include "AlertSystemConfigInfo.dat"
}

#undef CONFIGURE_COOLING_TYPES_INFO


void AlertSystem::initializeBatteriesInfo()
{
   _batteriesInfo = getBatteriesInfo();
}


void AlertSystem::initializeCoolingTypesInfo()
{
   _coolingTypesInfo = getCoolingTypesInfo();
}


BatteryInfo* AlertSystem::getBatteryInfo(const int id) const
{
   BatteryInfo* info = NULL;
   for (BatteryInfo::iterator itr = _batteriesInfo.begin(); itr != _batteriesInfo.end(); ++itr)
   {
      if ((*itr).getId() == id)
      {
         info = &(*itr);
         break;
      }
   }
   return info;
}


CoolingTypeInfo* AlertSystem::getCoolingTypeInfo(const enCoolingType type) const
{
   CoolingTypeInfo* info = NULL;
   for (CoolingTypeInfo::iterator itr = _coolingTypesInfo.begin(); itr != _coolingTypesInfo.end(); ++itr)
   {
      if ((*itr).getCoolingType() == type)
      {
         info = &(*itr);
         break;
      }
   }
   return info;
}


enCoolingType AlertSystem::getCoolingTypeForBattery(const int id) const
{
   enCoolingType type = COOLING_TYPE_UNKNOWN;
   const BatteryInfo* info = getBatteryInfo(id);
   if (NULL != info)
   {
      type = info->getCoolingType();
   }
   return type;
}


int AlertSystem::getMinTempLimitForCoolingType(const enCoolingType type) const
{
   int minTemp = -1;
   const CoolingTypeInfo* info = getCoolingTypeInfo(type);
   if (NULL != info)
   {
      minTemp = info->getMinTempLimit();
   }
   return minTemp;
}


int AlertSystem::getMaxTempLimitForCoolingType(const enCoolingType type) const
{
   int maxTemp = -1;
   const CoolingTypeInfo* info = getCoolingTypeInfo(type);
   if (NULL != info)
   {
      maxTemp = info->getMaxTempLimit();
   }
   return maxTemp;
}

enBreachType AlertSystem::inferBreachForCoolingType(const enCoolingType type, const double currentTemp)
{
   enBreachType bType = BREACH_TYPE_NORMAL;
   const int minTemp = getMinTempLimitForCoolingType(type);
   const int maxTemp = getMaxTempLimitForCoolingType(type);
   if(currentTemp < minTemp)
   {
     bType = BREACH_TYPE_TOO_LOW;
   }
   else if(currentTemp > maxTemp)
   {
     bType = BREACH_TYPE_TOO_HIGH;
   }
   else
   {}
   return bType;
}


void AlertSystem::informBreachInfoToController(const enBreachType bType)
{
   if (_controller != "")
   {
      const unsigned short header = 0xfeed;
      printf("Info To: %s\n", _controller.c_str());
      printf("%x : %x\n", header, breachType);
   }
   else
   {
      ::std::string info = (bType == BREACH_TYPE_TOO_LOW) ? "too low" : "too high";
      const char* recepient = "a.b@c.com";
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is %s\n", info.c_str());
   }
}


enBreachType AlertSystem::checkBreachAndAlert(const int id, const double currentTemp)
{
   enCoolingType type = getCoolingTypeForBattery(id);
   enBreachType bType = inferBreachForCoolingType(type, currentTemp);
   if (bType != BREACH_TYPE_NORMAL)
   {
      informBreachInfoToController(bType);
   }
   return bType;
}