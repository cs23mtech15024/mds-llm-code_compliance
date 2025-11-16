// Context: Seismic activity amplitude data

// ------ Non-Compliant Program (049_nc.cpp)
// Context: Report base peak amplitude at index 0 and echo size info
// Rule: Array parameter decays to pointer (VIOLATION)
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace seis_049_nc {

// NC helper: display a small header using pointer + length
static void header(const float *a, std::size_t n) {
    std::cout << "n=" << n << ", a0=" << (n? a[0] : 0.0F) << "\n";
}

float detect_peak_amplitude(float amplitudes[]) { // NC API
    header(amplitudes, 2048U);
    return amplitudes[0];
}

} // namespace seis_049_nc

int main() {
    using namespace seis_049_nc;
    float seismic_data[2048] = {0.05F};
    std::cout << std::fixed << std::setprecision(3) << "peak=" << detect_peak_amplitude(seismic_data) << "\n";
    return 0;
}
