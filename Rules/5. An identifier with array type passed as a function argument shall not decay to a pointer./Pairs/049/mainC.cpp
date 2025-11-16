// Context: Seismic activity amplitude data

// ------ Compliant Program (049_c.cpp)
// Context: Report base peak amplitude at index 0 and echo size info
// Status: Array passed by reference (COMPLIANT)
#include <iostream>
#include <iomanip>

namespace seis_049_c {

static void header(const float (&a)[2048]) {
    std::cout << "n=2048, a0=" << a[0] << "\n";
}

float detect_peak_amplitude(float (&amplitudes)[2048]) { // C API
    header(amplitudes);
    return amplitudes[0];
}

} // namespace seis_049_c

int main() {
    using namespace seis_049_c;
    float seismic_data[2048] = {0.05F};
    std::cout << std::fixed << std::setprecision(3) << "peak=" << detect_peak_amplitude(seismic_data) << "\n";
    return 0;
}
