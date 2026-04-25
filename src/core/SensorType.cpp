#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/core/SensorType.hpp"

namespace sensor_alert {

std::string toString(SensorType type){
    switch (type){
        case SensorType::Temperature:
            return "TEMPERATURE";
        case SensorType::Pressure:
            return "PRESSURE";
        case SensorType::Voltage:
            return "VOLTAGE";
        case SensorType::Unknown:
        default:
            return "UNKNOWN"; 
    }
}

SensorType sensorTypeFromString(const std:: string& typeStr){
    if (typeStr == "TEMPERATURE"){
        return SensorType::Temperature;
    }
    if (typeStr == "PRESSURE"){
        return SensorType::Pressure;
    }
    if (typeStr == "VOLTAGE"){
        return SensorType::Voltage;
    }

    return SensorType::Unknown;
}

}
