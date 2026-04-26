#pragma once

namespace sensor_alert{

class ThresholdRule {
public:
    ThresholdRule(  double warningMin,
                    double warningMax,
                    double criticalMin,
                    double criticalMax);
    
    double getWarningMin() const;
    double getWarningMax() const;
    double getCriticalMin() const;
    double getCriticalMax() const;

private:
    double warningMin_;
    double warningMax_;
    double criticalMin_;
    double criticalMax_;
};

}