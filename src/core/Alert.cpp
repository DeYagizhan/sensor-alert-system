#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/core/Alert.hpp"

#include <utility>

namespace sensor_alert {

Alert::Alert(   std::string timestamp,
                std::string sensorId,
                SensorType sensorType,
                double value,
                AlertSeverity severity,
                std::string message):
    
    timestamp_(std::move(timestamp)),
    sensorId_(std::move(sensorId)),
    sensorType_(sensorType),
    value_(value),
    severity_(severity),
    message_(std::move(message)) {
}

const std::string& Alert::getTimestamp() const {
    return timestamp_;
}

const std::string& Alert::getSensorId() const {
    return sensorId_;
}

SensorType Alert::getSensorType() const {
    return sensorType_;
}

double Alert::getValue() const {
    return value_;
}

AlertSeverity Alert::getSeverity() const {
    return severity_;
}

const std::string& Alert::getMessage() const {
    return message_;
}

}