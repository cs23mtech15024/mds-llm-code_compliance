// Context: Real-time clock drift correction header

// -------- Non-Compliant Program (prog_026_nc.cpp)
// Context: RTC drift correction
#include <iostream>
#include <iomanip>
#include "seedNC.h" // seed026_drift_ppm, seed026_correct_time()

namespace rtc_nc {

double clamp(double v) {
    return (v < 0.0) ? 0.0 : v;
}

void process(double times[], std::size_t n) { // NC decay
    for (std::size_t i = 0; i < n; ++i) {
        double t = clamp(times[i]);
        double adj = seed026_correct_time(t); // header fn (NC)
        std::cout << "t=" << t << " adj=" << std::fixed << std::setprecision(6)
                  << adj << "\n";
    }
}

double max_val(double arr[], std::size_t n) { // NC
    double m = 0.0;
    for (std::size_t i = 0; i < n; ++i)
        if (arr[i] > m) m = arr[i];
    return m;
}

} // namespace rtc_nc

int main() {
    using namespace rtc_nc;
    double t[5] = {1.0, 10.0, 60.0, 120.0, 3600.0};
    process(t,5);
    std::cout << "max=" << max_val(t,5) << "\n";
    return 0;
}
