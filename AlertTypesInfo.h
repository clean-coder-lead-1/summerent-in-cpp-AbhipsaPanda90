/********************************************************************************
 * @file         : AlertTypesInfo.h
 * @author       : Abhipsa Panda
 * @brief        : Defines types information used for alert handling
 ********************************************************************************/


#ifndef ALERT_TYPES_INFO_H
#define ALERT_TYPES_INFO_H


#include "AlertTypesConstants.h"


class CoolingTypeInfo
{
   public:
      CoolingTypeInfo()
      {
         clear();
      }

      virtual ~CoolingTypeInfo()
      {
         clear();
      }

      CoolingTypeInfo(const CoolingTypeInfo& obj)
      {
         clear();
         *this = obj;
      }

      CoolingTypeInfo& operator = (const CoolingTypeInfo& obj)
      {
         if (this != &obj)
         {
            _coolingType  = obj.getCoolingType();
            _minTempLimit = obj.getMinTempLimit();
            _maxTempLimit = obj.getMaxTempLimit();
         }
         return *this;
      }

      inline void clear()
      {
         _coolingType  = COOLING_TYPE_UNKNOWN;
         _minTempLimit = 0;
         _maxTempLimit = 0;
      }

      inline void setCoolingType(const enCoolingType value)
      {
         _coolingType = value;
      }

      inline enCoolingType getCoolingType() const
      {
         return _coolingType;
      }

      inline void setMinTempLimit(const int value)
      {
         _minTempLimit = value;
      }

      inline int getMinTempLimit() const
      {
         return _minTempLimit;
      }

      inline void setMaxTempLimit(const int value)
      {
         _maxTempLimit = value;
      }

      inline int getMaxTempLimit() const
      {
         return _maxTempLimit;
      }

   private:
      enCoolingType _coolingType;
      int _minTempLimit;
      int _maxTempLimit;
};


class BatteryInfo
{
   public:
      BatteryInfo()
      {
         clear();
      }

      virtual ~BatteryInfo()
      {
         clear();
      }

      BatteryInfo(const BatteryInfo& obj)
      {
         clear();
         *this = obj;
      }

      BatteryInfo& operator = (const BatteryInfo& obj)
      {
         if (this != &obj)
         {
            _id          = obj.getId();
            _brand       = obj.getBrand();
            _coolingType = obj.getCoolingType();
         }
         return *this;
      }

      inline void clear()
      {
         _id          = 0;
         _brand       = "";
         _coolingType = COOLING_TYPE_UNKNOWN;
      }

      inline void setId(const int value)
      {
         _id = value;
      }

      inline int getId() const
      {
         return _id;
      }

      inline void setBrand(const ::std::string value)
      {
         _brand = value;
      }

      inline ::std::string getBrand() const
      {
         return _brand;
      }

      inline void setCoolingType(const enCoolingType value)
      {
         _coolingType = value;
      }

      inline enCoolingType getCoolingType() const
      {
         return _coolingType;
      }

   private:
      int _id;
      ::std::string _brand;
      enCoolingType _coolingType;
};


#endif // ALERT_TYPES_INFO_H