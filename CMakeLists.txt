cmake_minimum_required(VERSION 3.16)

project(sensor_alert_system VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(sensor_alert_system
    src/main.cpp
    src/core/SensorType.cpp
    src/core/AlertSeverity.cpp
    src/core/SensorReading.cpp
    src/core/ThresholdRule.cpp
    src/processing/ThresholdEvaluator.cpp
)

target_include_directories(sensor_alert_system
    PRIVATE
        include
)