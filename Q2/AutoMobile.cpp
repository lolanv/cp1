#include "Automobile.h"


std::ostream &operator<<(std::ostream &os, const AutoMobile &rhs) {
    os << "_id: " << rhs._id
       << " _type: " << static_cast<int>(rhs._type)
       << " _price: " << rhs._price
       << " _seat_count: " << rhs._seat_count
       << " _engin_horse_power: " << rhs._engin_horse_power;
    return os;
}

AutoMobile::AutoMobile(std::string id, AutoMobileType type, float price, int seat_count, int engin_horse_power) : _id{id}, _type{type}, _price{price}, _seat_count{seat_count}, _engin_horse_power{engin_horse_power}
{
}

float AutoMobile::CalculateGst()
{
    return 0.18f * price();
}
