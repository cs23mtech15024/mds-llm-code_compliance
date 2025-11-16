// Context: Navigation system compass calibration header

// -------- Compliant Program (prog_032_c.cpp)
// Context: Navigation compass calibration — COMPLIANT
#include <iostream>
#include <cmath>
#include "seedC.h"

// Definitions
double seed032_declination = -4.2;
double seed032_correct_heading(double h) { return h + seed032_declination; }

namespace nav_c {

double normalize(double h) {
    while (h < 0) h += 360;
    while (h >= 360) h -= 360;
    return h;
}

template <std::size_t N>
void process(const double (&headings)[N]) {
    for (std::size_t i = 0; i < N; ++i) {
        double c = seed032_correct_heading(headings[i]);
        std::cout << "raw=" << headings[i]
                  << " decl=" << seed032_declination
                  << " corr=" << normalize(c) << "\n";
    }
}

template <std::size_t N>
double avg(const double (&arr)[N]) {
    double s = 0;
    for (auto v : arr) s += v;
    return (N>0)? s/N : 0;
}

} // namespace nav_c

int main() {
    using namespace nav_c;
    const double h[4] = {10,350,45,270};
    process(h);
    std::cout << "avg=" << avg(h) << "\n";
    return 0;
}
