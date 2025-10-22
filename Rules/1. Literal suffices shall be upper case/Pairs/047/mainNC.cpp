// ------ Non-Compliant (Seed 047)
// Context: Engine Temperature Regulation — adjusting cooling rate based on temperature readings
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violation: lowercase suffixes 'f', 'u', 'l' in numeric literals.

#include <iostream>
#include <vector>
#include <iomanip>

struct TempConfig {
    float gain;         // scaling factor for cooling
    unsigned interval;  // sample interval
    long maxTemp;       // maximum safe temperature
};

class EngineMonitor {
public:
    explicit EngineMonitor(const TempConfig& cfg) : cfg_(cfg), temperature(75.0f) {} // non-compliant

    void update(const std::vector<float>& readings) {
        for (unsigned i = 0u; i < readings.size(); i += cfg_.interval) { // non-compliant
            float delta = readings[i] - temperature;
            temperature += cfg_.gain * delta; // non-compliant
            std::cout << "Temp[" << i << "] = " << std::fixed << std::setprecision(2)
                      << temperature << "°C\n";
            if (temperature > static_cast<float>(cfg_.maxTemp)) { // non-compliant
                std::cout << "⚠️  Overheat detected!\n";
                break;
            }
        }
    }

private:
    TempConfig cfg_;
    float temperature;
};

int main() {
    TempConfig cfg{1.2f, 50u, 120l}; // non-compliant
    std::vector<float> readings{75.0f, 85.5f, 90.0f, 95.2f, 121.0f}; // non-compliant

    EngineMonitor monitor(cfg);
    monitor.update(readings);
    return 0;
}