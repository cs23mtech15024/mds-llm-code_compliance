// ------ Non-Compliant (Seed 043)
// Context: Embedded Sensor Sampling — applying gain and offset calibration
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violation: lowercase 'f', 'u', 'l' used in literals.

#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>

struct SensorConfig {
    float gain;         // e.g., 2.5f
    long offset;        // e.g., -15l
    unsigned buffer;    // e.g., 512u
};

class Sensor {
public:
    explicit Sensor(const SensorConfig& cfg)
        : cfg_(cfg), data(cfg.buffer, 0.0f) {} // non-compliant

    void captureSamples() {
        for (unsigned i = 0u; i < cfg_.buffer; ++i) { // non-compliant
            data[i] = static_cast<float>(i % 100u) * cfg_.gain + static_cast<float>(cfg_.offset); // non-compliant
        }
    }

    float averageReading() const {
        float sum = std::accumulate(data.begin(), data.end(), 0.0f); // non-compliant
        return sum / static_cast<float>(cfg_.buffer);
    }

    void printSummary() const {
        std::cout << "Gain: " << cfg_.gain 
                  << " Offset: " << cfg_.offset 
                  << " Buffer: " << cfg_.buffer 
                  << " Avg: " << std::fixed << std::setprecision(2) << averageReading() << "\n";
    }

private:
    SensorConfig cfg_;
    std::vector<float> data;
};

int main() {
    SensorConfig cfg{2.5f, -15l, 512u}; // non-compliant
    Sensor sensor(cfg);
    sensor.captureSamples();
    sensor.printSummary();
    return 0;
}