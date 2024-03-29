#include <iostream>
#include <string>
#include "ChargingType.h"

class EvCar
{
private:
    float _Battery_capacity;
    float _price;
    ChargingType _charging_type;

public:
    EvCar() = default;                        // default constructor enabled
    EvCar(const EvCar &) = delete;            // disabled copy constructor
    EvCar &operator=(const EvCar &) = delete; // copy assignment operator disabled
    EvCar(EvCar &&) = delete;                 // move constructor disabled
    EvCar &operator=(EvCar &&) = delete;      // move assignment disabled
    ~EvCar() = default;                       // enabled destructor

    EvCar(float Battery_capacity,float price,ChargingType charging_type);

    float CalculateGst();

    float batteryCapacity() const { return _Battery_capacity; }
    void setBatteryCapacity(float Battery_capacity) { _Battery_capacity = Battery_capacity; }

    float price() const { return _price; }
    void setPrice(float price) { _price = price; }

    ChargingType chargingType() const { return _charging_type; }

    friend std::ostream &operator<<(std::ostream &os, const EvCar &rhs);
};