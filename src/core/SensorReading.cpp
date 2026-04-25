#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/core/SensorReading.hpp"

#include <utility>

namespace sensor_alert {

SensorReading::SensorReading(   std::string timestamp,
                                std::string sensorId,
                                SensorType sensorType,
                                double value):
        timestamp_(std::move(timestamp)),
        sensorId_(std::move(sensorId)),
        sensorType_(sensorType),
        value_(value){
}

const std::string& SensorReading::getTimestamp() const {
    return timestamp_;
}

const std::string& SensorReading::getSensorId() const {
    return sensorId_;
}

SensorType SensorReading::getSensorType() const {
    return sensorType_;
}

double SensorReading::getValue() const {
    return value_;
}

}