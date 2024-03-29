
#ifndef OPERATION_H
#define OPERATION_H

#include <memory>
#include <list>
#include <variant>
#include <vector>
#include "Automobile.h"
#include "DataEmptyException.h"
#include "EvCar1.h"
#include <thread>
#include <mutex>

using EvCarContainer = std::vector<std::shared_ptr<EvCar>>;

    class Operation
{
private:
    Operation();
    Operation(const Operation &) = delete;
    Operation &operator=(const Operation &) = delete;
    Operation(Operation &&) = delete;
    Operation &operator=(Operation &&) = delete;

    using VehicleVariant = std::variant<std::shared_ptr<EvCar>, std::shared_ptr<AutoMobile>>;

    std::list<VehicleVariant> m_data;


    static Operation *_only_object;

public:
    static Operation *GetInstance();

    void CreateObjects();

    void DisplayGST() const;
    void CountBySeatCount() const;
    void AveragePriceAutoMobile() const;
    void EvCarChargingTypeDC() const;

    ~Operation() = default;
};

#endif // OPERATION_H
