// Context: GNSS coordinate conversion parameters

// -------- Non-Compliant Program (prog_008_nc.cpp)
// Context: GNSS coordinate conversion
#include <iostream>
#include <cmath>
#include "seedNC.h"  // seed008_deg_to_rad, seed008_to_radians()

namespace gnss_nc {

void convert(double angles[], std::size_t n) { // NC decay
    for (std::size_t i = 0; i < n; ++i) {
        double r = seed008_to_radians(angles[i]);
        std::cout << angles[i] << " deg -> " << r << " rad\n";
    }
}

double sum(double arr[], std::size_t n) { // NC
    double s = 0;
    for (std::size_t i = 0; i < n; ++i) s += arr[i];
    return s;
}

} // namespace gnss_nc

int main() {
    using namespace gnss_nc;
    double vals[4] = {0.0,90.0,180.0,270.0};
    convert(vals,4);
    std::cout << "sum=" << sum(vals,4) << "\n";
    return 0;
}
