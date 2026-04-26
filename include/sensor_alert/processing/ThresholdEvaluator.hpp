#pragma once 

#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/core/AlertSeverity.hpp"
#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/core/SensorReading.hpp"
#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/core/ThresholdRule.hpp"

namespace sensor_alert {

class ThresholdEvaluator {

public:
    AlertSeverity evaluate( const SensorReading& reading,
                            const ThresholdRule& rule) const;
            
};

}