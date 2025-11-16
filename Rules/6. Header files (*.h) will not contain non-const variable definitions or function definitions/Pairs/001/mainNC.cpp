// Context: Battery management system threshold config header

// -------- Non-Compliant Program (prog_001_nc.cpp)
// Context: Battery management system threshold configuration
// Rule violated: Header contains non-const variable definitions + function definitions
#include <iostream>
#include <iomanip>
#include <cstddef>
#include "seedNC.h"  // uses seed001_low_voltage, seed001_high_voltage, seed001_compute_range()

namespace bms_001_nc {

static float clamp(float v, float lo, float hi) { // helper
    return (v < lo) ? lo : (v > hi ? hi : v);
}

void analyze(float arr[], std::size_t n) { // NC: decayed array
    std::cout << std::fixed << std::setprecision(2);
    for (std::size_t i = 0; i < n; ++i) {
        float v = clamp(arr[i], 2.5F, 4.5F);
        float scaled = seed001_compute_range(v);
        std::cout << "cell[" << i << "]=" << v;
        if (v < seed001_low_voltage) std::cout << " LOW";
        if (v > seed001_high_voltage) std::cout << " HIGH";
        std::cout << " scaled=" << scaled << "\n";
    }
}

float average(float arr[], std::size_t n) { // NC again (decay)
    float sum = 0.0F;
    for (std::size_t i = 0; i < n; ++i) sum += arr[i];
    return (n > 0U) ? sum / n : 0.0F;
}

} // namespace bms_001_nc

int main() {
    using namespace bms_001_nc;
    float cells[5] = {3.28F, 3.12F, 3.40F, 4.35F, 3.90F};
    analyze(cells, 5);
    std::cout << "avg=" << average(cells, 5) << "\n";
    return 0;
}
