#include "EvCar1.h"
std::ostream &operator<<(std::ostream &os, const EvCar &rhs) {
    os << "_Battery_capacity: " << rhs._Battery_capacity
       << " _price: " << rhs._price
       << " _charging_type: " <<static_cast<int>( rhs._charging_type);
    return os;
}

EvCar::EvCar(float Battery_capacity, float price, ChargingType charging_type)
: _Battery_capacity{Battery_capacity},_price{price},_charging_type{charging_type}  {
}

float EvCar::CalculateGst()
{
    return 0.10f * price();
}
