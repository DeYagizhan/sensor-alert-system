#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/processing/SensorManager.hpp"

namespace sensor_alert {

void SensorManager::addThresholdRule(   SensorType sensorType,
                                        const ThresholdRule& rule) {
    thresholdRules_.insert_or_assign(sensorType, rule);
}

AlertSeverity SensorManager::processReading(const SensorReading& reading) {
    readings_.push_back(reading);

    const auto ruleIt = thresholdRules_.find(reading.getSensorType());

    if (ruleIt == thresholdRules_.end()) {
        alertManager_.processReading(reading, AlertSeverity::Invalid);
        return AlertSeverity::Invalid;
    }

    const AlertSeverity severity = evaluator_.evaluate(reading, ruleIt->second);

    alertManager_.processReading(reading, severity);

    return severity;
    }

    const std::vector<SensorReading>& SensorManager::getReadings() const {
        return readings_;
    }

    const AlertManager& SensorManager::getAlertManager() const {
        return alertManager_;
    }
}