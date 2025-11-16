// Context: pH sensor calibration values

// ------ Compliant Program (026_c.cpp)
// Context: Store known pH points (simplified)
// Status: COMPLIANT (array by reference)
#include <iostream>
#include <iomanip>

namespace ph_026_c {

static void set_point(float (&vals)[3], std::size_t idx, float v) { // C helper
    vals[idx] = v;
}

void store_ph_calibration(float (&ph_values)[3]) { // C API
    set_point(ph_values, 0U, 7.0F);
    std::cout << std::fixed << std::setprecision(1)
              << "ph_neutral=" << ph_values[0] << "\n";
}

} // namespace ph_026_c

int main() {
    using namespace ph_026_c;
    float ph_cal[3] = {0};
    store_ph_calibration(ph_cal);
    return 0;
}
