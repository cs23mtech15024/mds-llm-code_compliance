// ------ Compliant (Seed 040)
// Context: Sensor Fusion — smoothing raw accelerometer data and applying drift compensation.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Fixes: Uppercase literal suffixes ('F','U','L') and uppercase hex digits (0X7FU).

#include <iostream>
#include <iomanip>
#include <array>
#include <cmath>
#include <cstdint>

struct AccelConfig {
    float alpha;
    unsigned status_mask;
    long sample_rate;
};

class AccelFilter {
public:
    explicit AccelFilter(const AccelConfig& cfg) : config(cfg) {
        smoothed = {0.0F, 0.0F, 0.0F};
    }

    void update(const std::array<float, 3>& raw) {
        for (int i = 0; i < 3; ++i) {
            smoothed[i] = config.alpha * raw[i] + (1.0F - config.alpha) * smoothed[i];
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
    AccelConfig cfg{0.2F, 0X7FU, 200L};
    AccelFilter filter(cfg);

    const std::array<std::array<float, 3>, 3> samples {{
        {0.1F, 0.2F, 0.9F}, {0.2F, 0.3F, 1.1F}, {0.15F, 0.25F, 1.0F}
    }};

    for (const auto& s : samples) {
        filter.update(s);
        filter.print();
    }

    unsigned status = cfg.status_mask & 0X7FU;
    std::cout << "Status mask applied: 0x" << std::hex << status << std::dec << "\n";
    return 0;
}