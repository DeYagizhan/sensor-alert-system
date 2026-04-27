#pragma once

#include <map>
#include <vector>

#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/core/AlertSeverity.hpp"
#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/core/SensorReading.hpp"
#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/core/SensorType.hpp"
#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/core/ThresholdRule.hpp"
#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/processing/AlertManager.hpp"
#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/processing/ThresholdEvaluator.hpp"

namespace sensor_alert {

class SensorManager {
public:
    void addThresholdRule(SensorType sensorType, const ThresholdRule& rule);

    AlertSeverity processReading(const SensorReading& reading);

    const std::vector<SensorReading>& getReadings() const;
    const AlertManager& getAlertManager() const;

private:
    std::vector<SensorReading> readings_;
    std::map<SensorType, ThresholdRule> thresholdRules_;

    ThresholdEvaluator evaluator_;
    AlertManager alertManager_;
};

}