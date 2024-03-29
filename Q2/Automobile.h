#include <iostream>
#include <string>
#include "AutoMobileType.h"

class AutoMobile
{
private:
    std::string _id;
    AutoMobileType _type;
    float _price;
    int _seat_count;
    int _engin_horse_power;

public:
    AutoMobile() = default; // default constructor enabled
    AutoMobile(const AutoMobile &) = delete; // disabled copy constructor
    AutoMobile &operator=(const AutoMobile &) = delete; // copy assignment operator disabled
    AutoMobile(AutoMobile &&) = delete;            // move constructor disabled
    AutoMobile &operator=(AutoMobile &&) = delete; // move assignment disabled
   ~AutoMobile() = default; // enabled destructor

   AutoMobile(std::string id, AutoMobileType type,float price,int seat_count,
   int engin_horse_power );

   std::string id() const { return _id; }
   void setId(const std::string &id) { _id = id; }

  float CalculateGst();

  AutoMobileType type() const { return _type; }

  float price() const { return _price; }

  int seatCount() const { return _seat_count; }

  void setEnginHorsePower(int engin_horse_power) { _engin_horse_power = engin_horse_power; }

  int enginHorsePower() const { return _engin_horse_power; }

  friend std::ostream &operator<<(std::ostream &os, const AutoMobile &rhs);
    
};


