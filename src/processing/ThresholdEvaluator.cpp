#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/processing/ThresholdEvaluator.hpp"

namespace sensor_alert {

AlertSeverity ThresholdEvaluator::evaluate( const SensorReading& reading,
                                            const ThresholdRule& rule) const {
    const double value = reading.getValue();

    if (value < rule.getCriticalMin() || value > rule.getCriticalMax()) {
        return AlertSeverity::Critical;
    }

    if (value < rule.getWarningMin() || value > rule.getWarningMax()) {
        return AlertSeverity::Warning;
    }

    return AlertSeverity::Normal;
}

}