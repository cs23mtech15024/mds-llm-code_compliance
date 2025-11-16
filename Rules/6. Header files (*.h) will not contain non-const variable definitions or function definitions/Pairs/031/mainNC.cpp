// Context: Thermal camera gain configuration

// -------- Non-Compliant Program (prog_031_nc.cpp)
// Context: Thermal camera gain config
#include <iostream>
#include <iomanip>
#include "seedNC.h" // seed031_gain, seed031_apply_gain()

namespace thermal_nc {

float clamp(float v) {
    return (v < 0.0F) ? 0.0F : v;
}

void apply_to_frame(float frame[], std::size_t n) { // NC: array decay
    for (std::size_t i = 0; i < n; ++i) {
        float x = clamp(frame[i]);
        float out = seed031_apply_gain(x); // uses header fn (NC)
        std::cout << "px=" << x << " gain=" << seed031_gain
                  << " out=" << out << "\n";
    }
}

float max_val(float arr[], std::size_t n) { // NC
    float m = 0.0F;
    for (std::size_t i = 0; i < n; ++i)
        if (arr[i] > m) m = arr[i];
    return m;
}

} // namespace thermal_nc

int main() {
    using namespace thermal_nc;
    float buf[6] = {0.1F,0.5F,1.0F,0.8F,0.3F,1.2F};
    apply_to_frame(buf,6);
    std::cout << "max=" << max_val(buf,6) << "\n";
    return 0;
}
