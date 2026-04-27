#pragma once

#include <vector>

#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/core/Alert.hpp"
#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/core/AlertSeverity.hpp"
#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/core/SensorReading.hpp"

namespace sensor_alert {

class AlertManager {
public:
    void processReading(const SensorReading& reading, AlertSeverity severity);

    const std::vector<Alert>& getAlerts() const;
    bool hasAlerts() const;
    const Alert& getLastAlert() const;

private:
    std::vector<Alert> alerts_;

    std::string buildMessage(   const SensorReading& reading,
                                AlertSeverity severity) const;
};

}