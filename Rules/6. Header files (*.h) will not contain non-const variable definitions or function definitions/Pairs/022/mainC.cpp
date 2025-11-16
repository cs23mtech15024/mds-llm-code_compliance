// Context: Power meter calibration header defining gains

// -------- Compliant Program (prog_022_c.cpp)
// Context: Power meter calibration — COMPLIANT
#include <iostream>
#include <iomanip>
#include "seedC.h"

// Definitions
double seed022_calibration_gain = 1.234;
double seed022_apply_gain(double v) { return v * seed022_calibration_gain; }

namespace cal_c {

double clamp(double v) {
    return (v < 0.0) ? 0.0 : v;
}

template <std::size_t N>
void measure(const double (&raw)[N]) {
    for (std::size_t i = 0; i < N; ++i) {
        double v = clamp(raw[i]);
        double out = seed022_apply_gain(v);
        std::cout << "raw=" << raw[i]
                  << " cal=" << std::fixed << std::setprecision(3)
                  << out << "\n";
    }
}

template <std::size_t N>
double sum(const double (&arr)[N]) {
    double s = 0;
    for (auto v : arr) s += v;
    return s;
}

} // namespace cal_c

int main() {
    using namespace cal_c;
    const double raw[5] = {1.2,2.5,3.0,-1.0,0.5};
    measure(raw);
    std::cout << "sum=" << sum(raw) << "\n";
    return 0;
}
