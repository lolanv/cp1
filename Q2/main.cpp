#include <iostream>
#include "Operation.h"
#include <future>


int main()
{
    // Create an instance of Operation
    Operation *operation = Operation::GetInstance();

    // Create objects
    operation->CreateObjects();

    std::thread t1(&Operation::CreateObjects,operation);
    
    if (t1.joinable())
    {
        t1.join();
    }

    std::thread t2(&Operation::CountBySeatCount,operation);
    std::thread t3(&Operation::DisplayGST,operation);
    std::thread t4(&Operation::EvCarChargingTypeDC,operation);
    std::thread t5(&Operation::AveragePriceAutoMobile,operation);

    if (t2.joinable())
    {
        t2.join();
    }

    if (t3.joinable())
    {
        t3.join();
    }

    if (t4.joinable())
    {
        t4.join();
    }

    if (t5.joinable())
    {
        t5.join();
    }

    // Cleanup
    delete operation;

    return 0;
}
