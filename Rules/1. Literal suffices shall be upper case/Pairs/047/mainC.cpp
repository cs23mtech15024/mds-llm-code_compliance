// ------ Compliant (Seed 047)
// Context: Engine Temperature Regulation — adjusting cooling rate based on temperature readings
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Fix: Converted 'f', 'u', 'l' to uppercase 'F', 'U', 'L'.

#include <iostream>
#include <vector>
#include <iomanip>

struct TempConfig {
    float gain;
    unsigned interval;
    long maxTemp;
};

class EngineMonitor {
public:
    explicit EngineMonitor(const TempConfig& cfg) : cfg_(cfg), temperature(75.0F) {}

    void update(const std::vector<float>& readings) {
        for (unsigned i = 0U; i < readings.size(); i += cfg_.interval) {
            float delta = readings[i] - temperature;
            temperature += cfg_.gain * delta;
            std::cout << "Temp[" << i << "] = " << std::fixed << std::setprecision(2)
                      << temperature << "°C\n";
            if (temperature > static_cast<float>(cfg_.maxTemp)) {
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
    TempConfig cfg{1.2F, 50U, 120L};
    std::vector<float> readings{75.0F, 85.5F, 90.0F, 95.2F, 121.0F};

    EngineMonitor monitor(cfg);
    monitor.update(readings);
    return 0;
}