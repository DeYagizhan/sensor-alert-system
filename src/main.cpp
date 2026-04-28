#include <iostream>

#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/core/Alert.hpp"
#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/core/AlertSeverity.hpp"
#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/core/SensorReading.hpp"
#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/core/SensorType.hpp"
#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/core/ThresholdRule.hpp"
#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/io/CsvSensorDataReader.hpp"
#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/processing/SensorManager.hpp"

int main(){
    sensor_alert::SensorManager sensorManager;
    
    sensorManager.addThresholdRule(
        sensor_alert::SensorType::Temperature,
        sensor_alert::ThresholdRule(
            0.0, //warning min
            70.0, //warning max
            -10.0, //critical min
            85.0 //critical max     
        )
    );

    sensorManager.addThresholdRule(
        sensor_alert::SensorType::Pressure,
        sensor_alert::ThresholdRule(
            90.0, //warning min
            140.0, //warning max
            70.0, //critical min
            150.0 //critical max     
        )
    );

    sensorManager.addThresholdRule(
        sensor_alert::SensorType::Voltage,
        sensor_alert::ThresholdRule(
            22.0, //warning min
            28.0, //warning max
            18.0, //critical min
            30.0 //critical max     
        )
    );
    
    sensor_alert::CsvSensorDataReader reader("data/sample_sensor_data.csv");
    const std::vector<sensor_alert::SensorReading> readings = reader.readAll();

    std::cout << "Sensor Data Processing and Alert Managment System" << std::endl;
    std::cout << "Developers: Yagizhan Demir - Burak Dinarli" << std:: endl << std:: endl;
    std::cout << "---------------------------------------------------------------------" << std::endl;

    for (   const sensor_alert::SensorReading& reading : readings) {
            const sensor_alert::AlertSeverity severity = sensorManager.processReading(reading);

            std::cout   << reading.getTimestamp()
                        << " | "
                        << reading.getSensorId()
                        << " | "
                        << sensor_alert::toString(reading.getSensorType())
                        << " | value="
                        << reading.getValue()
                        << " | severity="
                        <<sensor_alert::toString(severity)
                        << std::endl;
    }

    std::cout << "---------------------------------------------------------------------" << std::endl << std::endl;

    const sensor_alert::AlertManager& alertManager = sensorManager.getAlertManager();

    std::cout << "Total Reading: " << sensorManager.getReadings().size() << std::endl;
    std::cout << "Alert Count  : " << alertManager.getAlerts().size() << std::endl;

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
