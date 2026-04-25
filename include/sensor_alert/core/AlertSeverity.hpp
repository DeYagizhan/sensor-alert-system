#pragma once

#include <string>

namespace sensor_alert{

enum class AlertSeverity{
    Normal,
    Warning,
    Critical,
    Invalid
};

std::string toString(AlertSeverity severity);

}