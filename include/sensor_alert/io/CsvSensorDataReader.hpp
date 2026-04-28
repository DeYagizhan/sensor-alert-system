#pragma once

#include <string>
#include <vector>

#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/core/SensorReading.hpp"
#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/io/ISensorDataReader.hpp"

namespace sensor_alert {

class CsvSensorDataReader : public ISensorDataReader {
public:
    explicit CsvSensorDataReader(std::string filePath);

    std::vector<SensorReading> readAll() override;

private:
    std::string filePath_;

    SensorReading parseLine(const std::string& line) const;
    std::vector<std::string> split(const std::string& line, char delimiter) const;

};

}