// Context: Wireless RSSI smoothing parameters header

// -------- Non-Compliant Program (prog_027_nc.cpp)
// Context: Wireless RSSI smoothing
#include <iostream>
#include <cmath>
#include "seedNC.h" // seed027_window_size, seed027_smooth()

namespace rssi_nc {

float avg(float arr[], std::size_t n) { // NC
    float s = 0.0F;
    for (std::size_t i = 0; i < n; ++i) s += arr[i];
    return (n>0)? s/n : 0.0F;
}

void smooth_seq(float buf[], std::size_t n) { // NC decay
    for (std::size_t i = 0; i < n; ++i) {
        float sm = seed027_smooth(buf); // header fn uses decayed array
        std::cout << "rssi=" << buf[i]
                  << " smoothed=" << sm
                  << " window=" << seed027_window_size << "\n";
    }
}

} // namespace rssi_nc

int main() {
    using namespace rssi_nc;
    float r[5] = {-70.5F, -68.0F, -72.3F, -69.1F, -71.0F};
    smooth_seq(r,5);
    std::cout << "avg=" << avg(r,5) << "\n";
    return 0;
}
