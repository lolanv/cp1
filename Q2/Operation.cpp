#include "Operation.h"
std::mutex mt;



Operation *Operation::_only_object = nullptr;

Operation::Operation() {}

Operation *Operation::GetInstance()
{
    if (!_only_object)
    {
        _only_object = new Operation();
    }
    return _only_object;
}

void Operation::CreateObjects()
{

    //   EvCAR Object
        m_data.push_back(std::make_shared<EvCar>(90.0f,80000,ChargingType::DC));
        m_data.push_back(std::make_shared<EvCar>(40.0f,90000,ChargingType::AC));


    //   Automobile Object
        m_data.push_back(std::make_shared<AutoMobile>("123",AutoMobileType::REGULAR,60000,5,2000));
        m_data.push_back(std::make_shared<AutoMobile>("124",AutoMobileType::REGULAR,60000,5,1000));
        m_data.push_back(std::make_shared<AutoMobile>("125",AutoMobileType::REGULAR,70000,5,3000));
  
}

void Operation::DisplayGST() const
{
    if(m_data.empty()){
        throw DataEmptyException("Data is empty !!");
    }
    for (const auto &vehicle : m_data)
        {
            if (auto touristVehicle = std::get_if<std::shared_ptr<EvCar>>(&vehicle))
            {
                std::lock_guard<std::mutex> lck(mt);
               std::cout <<"GST: " << touristVehicle->get()->CalculateGst() << std::endl;
            }
        }
}

void Operation::CountBySeatCount() const
{
    if (m_data.empty())
    {
        throw DataEmptyException("Data is empty !!");
    }
    int count{0};
    for (const auto &vehicle : m_data)
    {
        if (auto touristVehicle = std::get_if<std::shared_ptr<AutoMobile>>(&vehicle))
        {
            if(touristVehicle->get()->seatCount()>4){
                count++;
            }
        }
    }
    std::lock_guard<std::mutex> lck(mt);
    std::cout << "count "<< count;
}



void Operation::AveragePriceAutoMobile() const
{
    if (m_data.empty())
    {
        throw DataEmptyException("Data is empty !!");
    }
    float total = 0.0f;
        int count = 0;

        for (const auto &vehicle : m_data)
        {
            if (auto touristVehicle = std::get_if<std::shared_ptr<AutoMobile>>(&vehicle))
            {
                total += (*touristVehicle)->price();
                ++count;
            }
        }
        std::lock_guard<std::mutex> lck(mt);

        std::cout << "Average: " <<total/count <<std::endl;
}

void Operation::EvCarChargingTypeDC() const
{
    if (m_data.empty())
    {
        throw DataEmptyException("Data is empty !!");
    }
    bool flag =false;

    for (const auto &vehicle : m_data)
    {
        if (auto touristVehicle = std::get_if<std::shared_ptr<EvCar>>(&vehicle))
        {
            if (touristVehicle->get()->chargingType()==  ChargingType::DC)
            {
                flag = true;
                break;
            }
        }
    }
    std::lock_guard<std::mutex> lck(mt);
    std::cout << "flag " << flag;
}






















// float Operation::GetAverageTouristVehiclePrice() const
// {
//     float total = 0.0f;
//     int count = 0;

//     for (const auto &vehicle : m_data)
//     {
//         if (auto touristVehicle = std::get_if<std::shared_ptr<TouristVehicle>>(&vehicle))
//         {
//             total += (*touristVehicle)->vehiclePrice();
//             ++count;
//         }
//     }

//     return count > 0 ? total / count : 0.0f;
// }

// bool Operation::AllVehiclePricesAboveThreshold(float threshold) const
// {
//     for (const VehicleVariant &vehicle : m_data)
//     {
//         if (std::holds_alternative<std::shared_ptr<TouristVehicle>>(vehicle) || std::holds_alternative<std::shared_ptr<PrivateVehicle>>(vehicle))
//         {
//                 float price =0.0f;

//             std::visit([&](auto &&v)
//                                      { price =  v->vehiclePrice(); },
//                                      vehicle);
//             if (price <= threshold)
//             {
//                 return false;
//             }
//         }
//     }
//     return true;
// }

// PrivateVehicleContainer Operation::GetPrivateVehicles() const
// {
    
//     std::list<std::shared_ptr<PrivateVehicle>> privateVehicles;

//     for (const auto &vehicle : m_data)
//     {
//         if (auto privateVehicle = std::get_if<std::shared_ptr<PrivateVehicle>>(&vehicle))
//         {
//             privateVehicles.push_back(*privateVehicle);
//         }
//     }


//     return privateVehicles;
// }
