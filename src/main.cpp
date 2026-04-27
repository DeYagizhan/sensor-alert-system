#include <iostream>

#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/core/Alert.hpp"
#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/core/AlertSeverity.hpp"
#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/core/SensorReading.hpp"
#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/core/SensorType.hpp"
#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/core/ThresholdRule.hpp"
#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/processing/AlertManager.hpp"
#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/processing/ThresholdEvaluator.hpp"

int main(){
    sensor_alert::SensorReading reading(
        "2026-04-24T10:00:00",
        "TEMP_01",
        sensor_alert::SensorType::Temperature,
        82.0
    );

    sensor_alert::ThresholdRule temperatureRule(
        0.0, //warning min
        70.0, //warning max
        -10.0, //critical min
        85.0 //critical max
    );

    sensor_alert::ThresholdEvaluator evaluator;
    sensor_alert::AlertSeverity severity = evaluator.evaluate(reading, temperatureRule);

    sensor_alert::AlertManager alertManager;
    alertManager.processReading(reading, severity);

    std::cout << "Sensor Data Processing and Alert Managment System" << std::endl;
    std::cout << "Developers: Yagizhan Demir - Burak Dinarli" << std:: endl;
    std::cout << "------------------------------------------------------" << std::endl << std::endl;

    std::cout << "Sample Sensor Reading:" << std::endl;
    std::cout << "Timestamp : " << reading.getTimestamp() << std::endl;
    std::cout << "Sensor ID : " << reading.getSensorId() << std::endl;
    std::cout << "Type      : " << sensor_alert::toString(reading.getSensorType()) << std::endl;
    std::cout << "Value     : " << reading.getValue() << std::endl;
    std::cout << "Severity  : " << sensor_alert::toString(severity) << std::endl << std::endl;

    std::cout << "------------------------------------------------------" << std::endl << std::endl;
    std::cout << "Alert Count: " << alertManager.getAlerts().size() << std::endl;

    if (alertManager.hasAlerts()) {
        const sensor_alert::Alert& lastAlert = alertManager.getLastAlert();

        std::cout << "Last Alert : " << std::endl;
        std::cout << "Timestamp  : " << lastAlert.getTimestamp() << std::endl;
        std::cout << "Sensor ID  : " << lastAlert.getSensorId() << std::endl;
        std::cout << "Type       : " << sensor_alert::toString(lastAlert.getSensorType()) << std::endl;
        std::cout << "Value      : " << lastAlert.getValue() << std::endl;
        std::cout << "Severity   : " << sensor_alert::toString(lastAlert.getSeverity()) << std::endl;
        std::cout << "Message    : " << lastAlert.getMessage() << std::endl;
    }

    return 0;
}

