// ------ Non-Compliant (Seed 040)
// Context: Sensor Fusion — smoothing raw accelerometer data and applying drift compensation.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violations: lowercase 'f', 'u', 'l' suffixes and lowercase hex digits in 0x7fu.

#include <iostream>
#include <iomanip>
#include <array>
#include <cmath>
#include <cstdint>

struct AccelConfig {
    float alpha;          // smoothing factor
    unsigned status_mask; // bitmask for sensor flags
    long sample_rate;     // samples per second
};

class AccelFilter {
public:
    explicit AccelFilter(const AccelConfig& cfg) : config(cfg) {
        smoothed = {0.0f, 0.0f, 0.0f}; // non-compliant
    }

    void update(const std::array<float, 3>& raw) {
        for (int i = 0; i < 3; ++i) {
            smoothed[i] = config.alpha * raw[i] + (1.0f - config.alpha) * smoothed[i]; // non-compliant
        }
    }

    void print() const {
        std::cout << std::fixed << std::setprecision(2)
                  << "Smoothed: (" << smoothed[0] << ", "
                  << smoothed[1] << ", " << smoothed[2] << ")\n";
    }

private:
    AccelConfig config;
    std::array<float, 3> smoothed;
};

int main() {
    AccelConfig cfg{0.2f, 0x7fu, 200l}; // non-compliant
    AccelFilter filter(cfg);

    const std::array<std::array<float, 3>, 3> samples {{
        {0.1f, 0.2f, 0.9f}, {0.2f, 0.3f, 1.1f}, {0.15f, 0.25f, 1.0f}
    }}; // non-compliant

    for (const auto& s : samples) {
        filter.update(s);
        filter.print();
    }

    unsigned status = cfg.status_mask & 0x7fu; // non-compliant
    std::cout << "Status mask applied: 0x" << std::hex << status << std::dec << "\n";
    return 0;
}