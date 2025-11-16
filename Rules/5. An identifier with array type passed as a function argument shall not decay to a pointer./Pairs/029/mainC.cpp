// Context: Magnetometer heading samples

// ------ Compliant Program (029_c.cpp)
// Context: Fetch first heading sample (deg)
// Status: COMPLIANT (array by reference)
#include <iostream>
#include <iomanip>

namespace mag_029_c {

float get_heading(float (&samples)[20]) { // C API
    return samples[0];
}

} // namespace mag_029_c

int main() {
    using namespace mag_029_c;
    float mag_headings[20] = {45.5F};
    std::cout << std::fixed << std::setprecision(1)
              << "heading=" << get_heading(mag_headings) << "\n";
    return 0;
}
