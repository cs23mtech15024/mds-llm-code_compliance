// Context: Drone IMU calibration scale factors

// -------- Compliant Program (prog_039_c.cpp)
// Context: Drone IMU calibration — COMPLIANT
#include <iostream>
#include "seedC.h"

// Definitions
float seed039_acc_scale = 0.98F;
float seed039_calibrate(float v) { return v * seed039_acc_scale; }

namespace imu_c {

float clamp(float v) { return v; }

template <std::size_t N>
void apply(const float (&vals)[N]) {
    for (auto v : vals) {
        float out = seed039_calibrate(v);
        std::cout << "raw=" << v
                  << " scale=" << seed039_acc_scale
                  << " cal=" << out << "\n";
    }
}

template <std::size_t N>
float avg(const float (&arr)[N]) {
    float s=0; for (auto v : arr) s+=v; return (N? s/N:0);
}

} // namespace imu_c

int main() {
    using namespace imu_c;
    const float d[5] = {0.1F,0.2F,0.3F,0.4F,0.5F};
    apply(d);
    std::cout << "avg=" << avg(d) << "\n";
    return 0;
}
