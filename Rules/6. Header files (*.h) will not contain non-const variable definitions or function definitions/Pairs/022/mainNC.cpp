// Context: Power meter calibration header defining gains

// -------- Non-Compliant Program (prog_022_nc.cpp)
// Context: Power meter calibration
#include <iostream>
#include <iomanip>
#include "seedNC.h" // seed022_calibration_gain, seed022_apply_gain()

namespace cal_nc {

double clamp(double v) {
    return (v < 0.0) ? 0.0 : v;
}

void measure(double raw[], std::size_t n) { // NC
    for (std::size_t i = 0; i < n; ++i) {
        double v = clamp(raw[i]);
        double out = seed022_apply_gain(v); // header function (NC)
        std::cout << "raw=" << raw[i]
                  << " cal=" << std::fixed << std::setprecision(3)
                  << out << "\n";
    }
}

double sum(double arr[], std::size_t n) {
    double s = 0;
    for (std::size_t i = 0; i < n; ++i) s += arr[i];
    return s;
}

} // namespace cal_nc

int main() {
    using namespace cal_nc;
    double raw[5] = {1.2, 2.5, 3.0, -1.0, 0.5};
    measure(raw,5);
    std::cout << "sum=" << sum(raw,5) << "\n";
    return 0;
}
