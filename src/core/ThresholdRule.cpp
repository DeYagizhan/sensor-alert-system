#include "/home/yagizhan/projects/sensor-alert-system/include/sensor_alert/core/ThresholdRule.hpp"

namespace sensor_alert {

ThresholdRule::ThresholdRule(   double warningMin,
                                double warningMax,
                                double criticalMin,
                                double criticalMax):
        warningMin_(warningMin),
        warningMax_(warningMax),
        criticalMin_(criticalMin),
        criticalMax_(criticalMax) {

}

double ThresholdRule::getWarningMin() const {
    return warningMin_;
}

double ThresholdRule::getWarningMax() const {
    return warningMax_;
}

double ThresholdRule::getCriticalMin() const {
    return criticalMin_;
}

double ThresholdRule::getCriticalMax() const {
    return criticalMax_;
}

}