#include <iostream>

#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/core/SensorReading.hpp"
#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/core/SensorType.hpp"

int main(){
    sensor_alert::SensorReading reading(
        "2026-04-24T10:00:00",
        "TEMP_01",
        sensor_alert::SensorType::Temperature,
        72.5
    );
    
    std::cout << "Sensor Data Processing and Alert Managment System" << std::endl;
    std::cout << "Developers: Yagizhan Demir - Burak Dinarli" << std:: endl;
    std::cout << "------------------------------------------------------" << std::endl;

    std::cout << "Sample Sensor Reading:" << std::endl;
    std::cout << "Timestamp : " << reading.getTimestamp() << std::endl;
    std::cout << "Sensor ID : " << reading.getSensorId() << std::endl;
    std::cout << "Type      : " << sensor_alert::toString(reading.getSensorType()) << std::endl;
    std::cout << "Value     : " << reading.getValue() << std::endl;

    return 0;
}
