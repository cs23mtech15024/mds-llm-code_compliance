// Context: Drone IMU calibration scale factors

// -------- Non-Compliant Program (prog_039_nc.cpp)
// Context: Drone IMU calibration
#include <iostream>
#include "seedNC.h" // seed039_acc_scale, seed039_calibrate()

namespace imu_nc {

float clamp(float v) { return v; }

void apply(float vals[], std::size_t n) { // NC
    for (std::size_t i = 0; i < n; ++i) {
        float out = seed039_calibrate(vals[i]);
        std::cout << "raw=" << vals[i]
                  << " scale=" << seed039_acc_scale
                  << " cal=" << out << "\n";
    }
}

float avg(float arr[], std::size_t n) {
    float s=0; for(size_t i=0;i<n;++i) s+=arr[i]; return (n? s/n:0);
}

} // namespace imu_nc

int main() {
    using namespace imu_nc;
    float d[5] = {0.1F,0.2F,0.3F,0.4F,0.5F};
    apply(d,5);
    std::cout << "avg=" << avg(d,5) << "\n";
    return 0;
}
