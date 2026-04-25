#pragma once

#include <string>

namespace sensor_alert{

enum class SensorType{
    Temperature,
    Pressure,
    Voltage,
    Unknown
};

std::string toString(SensorType type);
SensorType sensorTypeFromString(const std::string& typeStr);

}
