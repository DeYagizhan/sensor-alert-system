#pragma once

#include <vector>

#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/core/SensorReading.hpp"

namespace sensor_alert {

class ISensorDataReader {
public:
    virtual ~ISensorDataReader() = default;

    virtual std::vector<SensorReading> readAll() = 0;
};

}