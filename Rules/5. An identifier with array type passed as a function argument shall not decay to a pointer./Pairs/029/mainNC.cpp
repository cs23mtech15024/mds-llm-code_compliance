// Context: Magnetometer heading samples

// ------ Non-Compliant Program (029_nc.cpp)
// Context: Fetch first heading sample (deg)
// Status: VIOLATED (array decays)
#include <iostream>
#include <iomanip>

namespace mag_029_nc {

float get_heading(float samples[]) { // NC API
    return samples[0];
}

} // namespace mag_029_nc

int main() {
    using namespace mag_029_nc;
    float mag_headings[20] = {45.5F};
    std::cout << std::fixed << std::setprecision(1)
              << "heading=" << get_heading(mag_headings) << "\n";
    return 0;
}
