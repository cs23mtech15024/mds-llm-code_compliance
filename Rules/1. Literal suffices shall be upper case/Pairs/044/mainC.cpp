// ------ Compliant (Seed 044)
// Context: Vehicle Speed Monitoring — detecting over-speeding events and counting alerts
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Fix: All lowercase suffixes ('f', 'u', 'l') converted to uppercase ('F', 'U', 'L').

#include <iostream>
#include <vector>
#include <iomanip>

struct SpeedConfig {
    float threshold;
    unsigned sample_rate;
    long max_alerts;
};

class SpeedMonitor {
public:
    explicit SpeedMonitor(const SpeedConfig& cfg)
        : cfg_(cfg), alerts(0L) {}

    void monitor(const std::vector<float>& speeds) {
        unsigned count = 0U;
        for (float spd : speeds) {
            ++count;
            if (count % cfg_.sample_rate == 0U && spd > cfg_.threshold) {
                ++alerts;
                std::cout << "⚠️  Alert! Speed = " << spd << " km/h (Threshold: " 
                          << cfg_.threshold << ")\n";
                if (alerts >= cfg_.max_alerts) {
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
    SpeedConfig cfg{80.5F, 100U, 5L};
    SpeedMonitor monitor(cfg);

    std::vector<float> data = {60.2F, 81.3F, 78.0F, 85.5F, 90.2F, 79.9F};
    monitor.monitor(data);

    return 0;
}