// ------ Non-Compliant (Seed 050)
// Context: Drone Altitude Stabilization — maintain altitude via PID-like gain control
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violation: lowercase suffixes 'f', 'u', and 'l' in numeric literals.

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

struct FlightConfig {
    float altitudeGain;
    unsigned loopDelay;
    long maxFlightTime;
};

class AltitudeController {
public:
    AltitudeController(const FlightConfig& cfg)
        : cfg_(cfg), altitude_(0.0f), desired_(100.0f), time_(0l) {} // non-compliant

    void stabilize(const std::vector<float>& sensorData) {
        for (unsigned i = 0u; i < sensorData.size(); ++i) { // non-compliant
            float error = desired_ - sensorData[i];
            altitude_ += cfg_.altitudeGain * error * 0.1f; // non-compliant

            std::cout << "T=" << time_ << "s, Altitude=" << std::fixed
                      << std::setprecision(2) << altitude_ << "m\n";

            time_ += cfg_.loopDelay;
            if (time_ > cfg_.maxFlightTime) {
                std::cout << "⚠️  Max flight time reached, shutting down motors.\n";
                break;
            }
        }
    }

private:
    FlightConfig cfg_;
    float altitude_;
    float desired_;
    long time_;
};

int main() {
    FlightConfig cfg{0.75f, 20u, 7200l}; // non-compliant
    std::vector<float> sensorData{90.0f, 95.0f, 99.0f, 100.0f, 101.0f}; // non-compliant

    AltitudeController controller(cfg);
    controller.stabilize(sensorData);
    return 0;
}