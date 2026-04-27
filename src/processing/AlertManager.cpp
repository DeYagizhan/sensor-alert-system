#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/processing/AlertManager.hpp"

#include <stdexcept>

#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/core/SensorType.hpp"

namespace sensor_alert {

void AlertManager::processReading(  const SensorReading& reading,
                                    AlertSeverity severity) {
    if (severity == AlertSeverity::Normal) {
        return;
    }

    Alert alert(
            reading.getTimestamp(),
            reading.getSensorId(),
            reading.getSensorType(),
            reading.getValue(),
            severity,
            buildMessage(reading, severity)
    );

    alerts_.push_back(alert);
}

const std::vector<Alert>& AlertManager::getAlerts() const {
    return alerts_;
}

bool AlertManager::hasAlerts() const {
    return !alerts_.empty();
}

const Alert& AlertManager::getLastAlert() const {
    if (alerts_.empty()) {
        throw std::runtime_error("No alerts avaliable");
    }

    return alerts_.back();
}

std::string AlertManager::buildMessage( const SensorReading& reading,
                                        AlertSeverity severity) const {
    return  toString(severity) + " alert for sensor " + 
            reading.getSensorId() + " (" +
            toString(reading.getSensorType()) + "), value=" +
            std::to_string(reading.getValue());
}

}