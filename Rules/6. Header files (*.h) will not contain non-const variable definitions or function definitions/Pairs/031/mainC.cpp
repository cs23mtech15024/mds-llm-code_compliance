// Context: Thermal camera gain configuration

// -------- Compliant Program (prog_031_c.cpp)
// Context: Thermal camera gain config — COMPLIANT
#include <iostream>
#include <iomanip>
#include "seedC.h"

// Definitions
float seed031_gain = 1.75F;
float seed031_apply_gain(float x) { return x * seed031_gain; }

namespace thermal_c {

float clamp(float v) { return (v < 0.0F) ? 0.0F : v; }

template <std::size_t N>
void apply_to_frame(const float (&frame)[N]) {
    for (std::size_t i = 0; i < N; ++i) {
        float x = clamp(frame[i]);
        float out = seed031_apply_gain(x);
        std::cout << "px=" << x << " gain=" << seed031_gain
                  << " out=" << out << "\n";
    }
}

template <std::size_t N>
float max_val(const float (&arr)[N]) {
    float m = 0.0F;
    for (auto v : arr) if (v > m) m = v;
    return m;
}

} // namespace thermal_c

int main() {
    using namespace thermal_c;
    const float buf[6] = {0.1F,0.5F,1.0F,0.8F,0.3F,1.2F};
    apply_to_frame(buf);
    std::cout << "max=" << max_val(buf) << "\n";
    return 0;
}
