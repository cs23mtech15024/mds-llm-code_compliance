// ------ Non-Compliant (Seed 044)
// Context: Vehicle Speed Monitoring — detecting over-speeding events and counting alerts
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violation: lowercase 'f', 'u', 'l' suffixes in floating-point, unsigned, and long literals.

#include <iostream>
#include <vector>
#include <iomanip>

struct SpeedConfig {
    float threshold;      // e.g., 80.5f
    unsigned sample_rate; // e.g., 100u
    long max_alerts;      // e.g., 5l
};

class SpeedMonitor {
public:
    explicit SpeedMonitor(const SpeedConfig& cfg)
        : cfg_(cfg), alerts(0l) {} // non-compliant

    void monitor(const std::vector<float>& speeds) {
        unsigned count = 0u; // non-compliant
        for (float spd : speeds) {
            ++count;
            if (count % cfg_.sample_rate == 0u && spd > cfg_.threshold) { // non-compliant
                ++alerts;
                std::cout << "⚠️  Alert! Speed = " << spd << " km/h (Threshold: " 
                          << cfg_.threshold << ")\n";
                if (alerts >= cfg_.max_alerts) { // non-compliant
                    std::cout << "System entering safe mode...\n";
                    break;
                }
            }
        }
    }

private:
    SpeedConfig cfg_;
    long alerts;
};

int main() {
    SpeedConfig cfg{80.5f, 100u, 5l}; // non-compliant
    SpeedMonitor monitor(cfg);

    std::vector<float> data = {60.2f, 81.3f, 78.0f, 85.5f, 90.2f, 79.9f}; // non-compliant
    monitor.monitor(data);

    return 0;
}