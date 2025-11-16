// Context: Accelerometer calibration data

// ------ Compliant Program (011_c.cpp)
// Context: Apply simple offset calibration to 3-axis accelerometer
// Rule: Array arg shall not decay — COMPLIANT via reference to fixed-size array
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace accel_011_c {

static void add_bias(float (&v)[3], float dx, float dy, float dz) { // C helper
    v[0] += dx; v[1] += dy; v[2] += dz;
}

static void clamp3(float (&v)[3], float lo, float hi) { // C helper
    for (std::size_t i = 0; i < 3U; ++i) {
        if (v[i] < lo) v[i] = lo; else if (v[i] > hi) v[i] = hi;
    }
}

static void print3(const float (&v)[3], const char *label) { // C helper
    std::cout << label << ": ["
              << std::fixed << std::setprecision(3)
              << v[0] << ", " << v[1] << ", " << v[2] << "]\n";
}

void apply_calibration(float (&offsets)[3]) { // C API (no decay)
    print3(offsets, "before");
    add_bias(offsets, 0.050F, 0.000F, -0.020F);
    clamp3(offsets, -1.000F, 1.000F);
    print3(offsets, "after");
}

} // namespace accel_011_c

int main() {
    using namespace accel_011_c;
    float accel_offsets[3] = {0.000F, 0.000F, 0.000F};
    apply_calibration(accel_offsets);
    return 0;
}
