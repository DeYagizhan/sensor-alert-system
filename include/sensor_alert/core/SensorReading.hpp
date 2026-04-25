#pragma once

#include <string>

#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/core/SensorType.hpp"

namespace sensor_alert {

class SensorReading {
public:
    SensorReading(  std::string timestamp,
                    std::string sensorId,
                    SensorType sensorType,
                    double value);

    const std::string& getTimestamp() const;
    const std::string& getSensorId() const;
    SensorType getSensorType() const;
    double getValue() const;

private:
    std::string timestamp_;
    std::string sensorId_;
    SensorType sensorType_;
    double value_;
};

}