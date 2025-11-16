// Context: Real-time clock drift correction header

// -------- Compliant Program (prog_026_c.cpp)
// Context: RTC drift correction — COMPLIANT
#include <iostream>
#include <iomanip>
#include "seedC.h"

// Definitions
double seed026_drift_ppm = -2.5;
double seed026_correct_time(double t) { return t + t * (seed026_drift_ppm / 1e6); }

namespace rtc_c {

double clamp(double v) { return (v < 0.0) ? 0.0 : v; }

template <std::size_t N>
void process(const double (&times)[N]) {
    for (std::size_t i = 0; i < N; ++i) {
        double t = clamp(times[i]);
        double adj = seed026_correct_time(t);
        std::cout << "t=" << t << " adj=" << std::fixed << std::setprecision(6)
                  << adj << "\n";
    }
}

template <std::size_t N>
double max_val(const double (&arr)[N]) {
    double m = 0.0;
    for (auto v : arr) if (v > m) m = v;
    return m;
}

} // namespace rtc_c

int main() {
    using namespace rtc_c;
    const double t[5] = {1.0,10.0,60.0,120.0,3600.0};
    process(t);
    std::cout << "max=" << max_val(t) << "\n";
    return 0;
}
