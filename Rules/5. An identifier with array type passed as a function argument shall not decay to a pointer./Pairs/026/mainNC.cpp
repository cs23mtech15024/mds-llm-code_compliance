// Context: pH sensor calibration values

// ------ Non-Compliant Program (026_nc.cpp)
// Context: Store known pH points (simplified)
// Status: VIOLATED (array decays)
#include <iostream>
#include <iomanip>

namespace ph_026_nc {

static void set_point(float *vals, std::size_t idx, float v) { // NC helper
    vals[idx] = v;
}

void store_ph_calibration(float ph_values[]) { // NC API
    set_point(ph_values, 0U, 7.0F);
    std::cout << std::fixed << std::setprecision(1)
              << "ph_neutral=" << ph_values[0] << "\n";
}

} // namespace ph_026_nc

int main() {
    using namespace ph_026_nc;
    float ph_cal[3] = {0};
    store_ph_calibration(ph_cal);
    return 0;
}
