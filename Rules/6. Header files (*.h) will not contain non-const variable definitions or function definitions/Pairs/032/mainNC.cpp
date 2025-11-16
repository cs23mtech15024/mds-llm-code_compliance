// Context: Navigation system compass calibration header

// -------- Non-Compliant Program (prog_032_nc.cpp)
// Context: Navigation compass calibration
#include <iostream>
#include <cmath>
#include "seedNC.h" // seed032_declination, seed032_correct_heading()

namespace nav_nc {

double normalize(double h) {
    while (h < 0) h += 360;
    while (h >= 360) h -= 360;
    return h;
}

void process(double headings[], std::size_t n) { // NC
    for (std::size_t i = 0; i < n; ++i) {
        double c = seed032_correct_heading(headings[i]); // header fn (NC)
        std::cout << "raw=" << headings[i]
                  << " decl=" << seed032_declination
                  << " corr=" << normalize(c) << "\n";
    }
}

double avg(double arr[], std::size_t n) { // NC
    double s = 0;
    for (std::size_t i = 0; i < n; ++i) s += arr[i];
    return (n>0)? s/n : 0;
}

} // namespace nav_nc

int main() {
    using namespace nav_nc;
    double h[4] = {10,350,45,270};
    process(h,4);
    std::cout << "avg=" << avg(h,4) << "\n";
    return 0;
}
