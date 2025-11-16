// Context: Wireless RSSI smoothing parameters header

// -------- Compliant Program (prog_027_c.cpp)
// Context: Wireless RSSI smoothing — COMPLIANT
#include <iostream>
#include <cmath>
#include "seedC.h"

// Definitions
int seed027_window_size = 5;
float seed027_smooth(float vals[]) { return vals[0]; }

namespace rssi_c {

template <std::size_t N>
float avg(const float (&arr)[N]) {
    float s = 0.0F;
    for (auto v : arr) s += v;
    return (N>0)? s/N : 0.0F;
}

template <std::size_t N>
void smooth_seq(const float (&buf)[N]) {
    for (std::size_t i = 0; i < N; ++i) {
        // Note: seed027_smooth still uses decayed ptr semantics but declared extern (C version ok)
        float sm = seed027_smooth(const_cast<float*>(buf));
        std::cout << "rssi=" << buf[i]
                  << " smoothed=" << sm
                  << " window=" << seed027_window_size << "\n";
    }
}

} // namespace rssi_c

int main() {
    using namespace rssi_c;
    const float r[5] = {-70.5F,-68.0F,-72.3F,-69.1F,-71.0F};
    smooth_seq(r);
    std::cout << "avg=" << avg(r) << "\n";
    return 0;
}
