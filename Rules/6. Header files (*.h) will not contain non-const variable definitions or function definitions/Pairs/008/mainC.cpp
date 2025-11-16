// Context: GNSS coordinate conversion parameters

// -------- Compliant Program (prog_008_c.cpp)
// Context: GNSS coordinate conversion — COMPLIANT
#include <iostream>
#include <cmath>
#include "seedC.h"

// Definitions
double seed008_deg_to_rad = 0.01745329252;
double seed008_to_radians(double d) { return d * seed008_deg_to_rad; }

namespace gnss_c {

template <std::size_t N>
void convert(const double (&angles)[N]) {
    for (std::size_t i = 0; i < N; ++i) {
        double r = seed008_to_radians(angles[i]);
        std::cout << angles[i] << " deg -> " << r << " rad\n";
    }
}

template <std::size_t N>
double sum(const double (&arr)[N]) {
    double s = 0;
    for (double v : arr) s += v;
    return s;
}

} // namespace gnss_c

int main() {
    using namespace gnss_c;
    const double vals[4] = {0.0,90.0,180.0,270.0};
    convert(vals);
    std::cout << "sum=" << sum(vals) << "\n";
    return 0;
}
