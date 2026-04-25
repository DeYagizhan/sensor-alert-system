#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/core/AlertSeverity.hpp"

namespace sensor_alert {

    std::string toString (AlertSeverity severity){
        switch (severity){
            case AlertSeverity::Normal:
                return "NORMAL";
            case AlertSeverity::Warning:
                return "WARNING";
            case AlertSeverity::Critical:
                return "CRITICAL";
            case AlertSeverity::Invalid:
            default:
                return "INVALID";
        }
    }
    
}