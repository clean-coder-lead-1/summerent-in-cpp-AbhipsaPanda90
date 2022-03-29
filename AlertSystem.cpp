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


BatteryInfo* AlertSystem::getBatteryInfo(int id)
{
   BatteryInfo* info = NULL;
   for (BatteriesInfo::iterator itr = _batteriesInfo.begin(); itr != _batteriesInfo.end(); ++itr)
   {
      if ((*itr).getId() == id)
      {
         info = &(*itr);
         break;
      }
   }
   return info;
}


CoolingTypeInfo* AlertSystem::getCoolingTypeInfo(enCoolingType type)
{
   CoolingTypeInfo* info = NULL;
   for (CoolingTypesInfo::iterator itr = _coolingTypesInfo.begin(); itr != _coolingTypesInfo.end(); ++itr)
   {
      if ((*itr).getCoolingType() == type)
      {
         info = &(*itr);
         break;
      }
   }
   return info;
}


enCoolingType AlertSystem::getCoolingTypeForBattery(int id)
{
   enCoolingType type = COOLING_TYPE_UNKNOWN;
   BatteryInfo* info = getBatteryInfo(id);
   if (NULL != info)
   {
      type = info->getCoolingType();
   }
   printf("getCoolingTypeForBattery = %d \n", type);
   return type;
}


int AlertSystem::getMinTempLimitForCoolingType(enCoolingType type)
{
   int minTemp = -1;
   CoolingTypeInfo* info = getCoolingTypeInfo(type);
   if (NULL != info)
   {
      minTemp = info->getMinTempLimit();
   }
   printf("getMinTempLimitForCoolingType = %d \n", minTemp);
   return minTemp;
}


int AlertSystem::getMaxTempLimitForCoolingType(enCoolingType type)
{
   int maxTemp = -1;
   CoolingTypeInfo* info = getCoolingTypeInfo(type);
   if (NULL != info)
   {
      maxTemp = info->getMaxTempLimit();
   }
   printf("getMaxTempLimitForCoolingType = %d \n", maxTemp);
   return maxTemp;
}

enBreachType AlertSystem::inferBreachForCoolingType(enCoolingType type, int currentTemp)
{
   enBreachType bType = BREACH_TYPE_NORMAL;
   int minTemp = getMinTempLimitForCoolingType(type);
   int maxTemp = getMaxTempLimitForCoolingType(type);
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
   printf("inferBreachForCoolingType = %d \n", bType);
   return bType;
}


void AlertSystem::informBreachInfoToController(enBreachType bType)
{
   if (_controller != "")
   {
      const unsigned short header = 0xfeed;
      printf("Info To: %s\n", _controller.c_str());
      printf("%x : %x\n", header, bType);
   }
   else
   {
      ::std::string info = (bType == BREACH_TYPE_TOO_LOW) ? "too low" : "too high";
      const char* recepient = "a.b@c.com";
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is %s\n", info.c_str());
   }
}


enBreachType AlertSystem::checkBreachAndAlert(int id, int currentTemp)
{
   enBreachType bType = BREACH_TYPE_UNKNOWN;
   enCoolingType type = getCoolingTypeForBattery(id);
   if (type != COOLING_TYPE_UNKNOWN)
   {
      bType = inferBreachForCoolingType(type, currentTemp);
      if (bType != BREACH_TYPE_NORMAL)
      {
         informBreachInfoToController(bType);
      }
   }
   printf("checkBreachAndAlert = %d \n", bType);
   return bType;
}