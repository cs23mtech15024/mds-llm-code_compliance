// Context: Battery management system threshold config header

// -------- Compliant Program (prog_001_c.cpp)
// Context: Battery management system threshold configuration
// COMPLIANT: Header has only extern declarations. Definitions are provided here.
#include <iostream>
#include <iomanip>
#include <cstddef>
#include "seedC.h"  // extern: seed001_low_voltage, seed001_high_voltage, seed001_compute_range()

// Provide definitions in THIS TU
float seed001_low_voltage = 3.2F;
float seed001_high_voltage = 4.2F;
float seed001_compute_range(float v) { return (v - seed001_low_voltage) * 10.0F; }

namespace bms_001_c {

static float clamp(float v, float lo, float hi) {
    return (v < lo) ? lo : (v > hi ? hi : v);
}

template <std::size_t N>
void analyze(const float (&arr)[N]) {
    std::cout << std::fixed << std::setprecision(2);
    for (std::size_t i = 0; i < N; ++i) {
        float v = clamp(arr[i], 2.5F, 4.5F);
        float scaled = seed001_compute_range(v);
        std::cout << "cell[" << i << "]=" << v;
        if (v < seed001_low_voltage) std::cout << " LOW";
        if (v > seed001_high_voltage) std::cout << " HIGH";
        std::cout << " scaled=" << scaled << "\n";
    }
}

template <std::size_t N>
float average(const float (&arr)[N]) {
    float sum = 0.0F;
    for (float v : arr) sum += v;
    return (N>0U) ? sum / N : 0.0F;
}

} // namespace bms_001_c

int main() {
    using namespace bms_001_c;
    const float cells[5] = {3.28F, 3.12F, 3.40F, 4.35F, 3.90F};
    analyze(cells);
    std::cout << "avg=" << average(cells) << "\n";
    return 0;
}
