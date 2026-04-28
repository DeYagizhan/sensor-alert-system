#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/io/CsvSensorDataReader.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <utility>

#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/core/SensorType.hpp"

namespace sensor_alert {

CsvSensorDataReader::CsvSensorDataReader(std::string filePath):
    filePath_(std::move(filePath)) {
}

std::vector<SensorReading> CsvSensorDataReader::readAll() {
    std::ifstream file(filePath_);

    if (!file.is_open()) {
        throw std::runtime_error("Failed to open CSV file: " + filePath_);
    }

    std::vector<SensorReading> readings;
    std::string line;

    //Header satirini atladik
    std::getline(file, line);

    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        readings.push_back(parseLine(line));
    }
    
    return readings;
}

SensorReading CsvSensorDataReader::parseLine(const std::string& line) const {
    const std::vector<std::string> columns = split(line, ',');

    if (columns.size() != 4) {
        throw std::runtime_error("Invalid CSV line: " + line);
    }

    const std::string& timestamp = columns[0];
    const std::string& sensorId = columns[1];
    const SensorType sensorType = sensorTypeFromString(columns[2]);
    const double value = std::stod(columns[3]);

    return SensorReading(timestamp, sensorId, sensorType, value);
}

std::vector<std::string> CsvSensorDataReader::split(const std::string& line,
                                                    char delimiter) const {
    std::vector<std::string> tokens;
    std::stringstream ss(line);
    std::string token;

    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;                                  
}

}