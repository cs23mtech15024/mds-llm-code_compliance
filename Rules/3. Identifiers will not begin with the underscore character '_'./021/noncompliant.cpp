// ------ Non-Compliant
// Seed: Non-compliant: int _sensorReading;   // Compliant: int sensorReading;
// Context: Sensor data class used in a DRDO environmental monitoring system.
// Violation: class member identifier begins with '_' — may be reserved (MISRA C++:2008 Rule 17-0-1).
// Sources: MathWorks / Polyspace — MISRA C++:2008 Rule 17-0-1 (reserved identifiers).
//          C++ standard / cppreference — identifier reservation rules (leading underscore / double underscore).
//          clang-tidy bugprone-reserved-identifier — tooling guidance on reserved identifiers.
//          StackOverflow Q&A: rules about using an underscore in a C++ identifier.
//          SEI/CERT DCL51 guidance on reserved identifiers.

#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <thread>
#include <cmath>

class EnvironmentalSensor {
private:
    int _sensorReading;  // NON-COMPLIANT: leading underscore in class member (seed)
    int sensorId;
    bool isActive;

public:
    EnvironmentalSensor(int id) : _sensorReading(0), sensorId(id), isActive(true) {}

    void updateReading(int rawValue) {
        // Simple calibration and filtering
        _sensorReading = static_cast<int>(rawValue * 0.95 + _sensorReading * 0.05);
        if (_sensorReading < 0) _sensorReading = 0;
        if (_sensorReading > 1000) _sensorReading = 1000;
    }

    int getReading() const { return _sensorReading; }
    int getId() const { return sensorId; }
    bool getStatus() const { return isActive; }

    void logData(std::ofstream& log) const {
        log << "[NC] sensor_id=" << sensorId << " reading=" << _sensorReading 
            << " status=" << (isActive ? "active" : "inactive") << '\n';
    }
};

void monitor_sensors_NC() {
    std::vector<EnvironmentalSensor> sensors;
    for (int i = 1; i <= 4; ++i) {
        sensors.emplace_back(i * 100);
    }

    std::ofstream log("env_sensor_nc.log", std::ios::app);
    if (!log) {
        std::cerr << "[NC] Log open failed\n";
        return;
    }

    // Simulate 10 measurement cycles
    for (int cycle = 0; cycle < 10; ++cycle) {
        for (auto& sensor : sensors) {
            // Deterministic synthetic readings
            int rawReading = 500 + static_cast<int>(50 * std::sin(cycle * 0.5 + sensor.getId() * 0.1));
            sensor.updateReading(rawReading);
            sensor.logData(log);
        }
        std::cout << "[NC] Cycle " << cycle << " completed\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }

    log.close();
}

int main() {
    monitor_sensors_NC();
    std::cout << "[NC] Environmental monitoring complete\n";
    return 0;
}