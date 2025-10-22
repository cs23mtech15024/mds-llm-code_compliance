// ------ Compliant (Seed 050)
// Context: Drone Altitude Stabilization — maintain altitude via PID-like gain control
// Fix: Changed all literal suffixes 'f', 'u', and 'l' → 'F', 'U', 'L'.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.

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
        : cfg_(cfg), altitude_(0.0F), desired_(100.0F), time_(0L) {}

    void stabilize(const std::vector<float>& sensorData) {
        for (unsigned i = 0U; i < sensorData.size(); ++i) {
            float error = desired_ - sensorData[i];
            altitude_ += cfg_.altitudeGain * error * 0.1F;

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
    FlightConfig cfg{0.75F, 20U, 7200L};
    std::vector<float> sensorData{90.0F, 95.0F, 99.0F, 100.0F, 101.0F};

    AltitudeController controller(cfg);
    controller.stabilize(sensorData);
    return 0;
}