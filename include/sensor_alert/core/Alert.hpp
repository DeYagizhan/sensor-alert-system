#pragma once

#include <string>

#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/core/AlertSeverity.hpp"
#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/core/SensorType.hpp"

namespace sensor_alert {

class Alert{
public:
    Alert(  std::string timestamp,
            std::string sensorId,
            SensorType sensorType,
            double value,
            AlertSeverity severity,
            std::string message);

    const std::string& getTimestamp() const;
    const std::string& getSensorId() const;
    SensorType getSensorType() const;
    double getValue() const;
    AlertSeverity getSeverity() const;
    const std::string& getMessage() const;

private:
    std::string timestamp_;
    std::string sensorId_;
    SensorType sensorType_;
    double value_;
    AlertSeverity severity_;
    std::string message_;

};
    
} 