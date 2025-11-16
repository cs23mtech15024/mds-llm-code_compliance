// Context: Accelerometer calibration data

// ------ Non-Compliant Program (011_nc.cpp)
// Context: Apply simple offset calibration to 3-axis accelerometer
// Rule: Array passed as function arg shall not decay to pointer — VIOLATED
// Note: helpers and API accept raw pointers/decayed arrays
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace accel_011_nc {

static void add_bias(float *v, float dx, float dy, float dz) { // NC helper
    if (!v) { return; }
    v[0] += dx; v[1] += dy; v[2] += dz;
}

static void clamp3(float *v, float lo, float hi) { // NC helper
    if (!v) { return; }
    for (std::size_t i = 0; i < 3U; ++i) {
        if (v[i] < lo) v[i] = lo; else if (v[i] > hi) v[i] = hi;
    }
}

static void print3(const float *v, const char *label) { // NC helper
    std::cout << label << ": ["
              << std::fixed << std::setprecision(3)
              << v[0] << ", " << v[1] << ", " << v[2] << "]\n";
}

void apply_calibration(float offsets[]) { // NC API (decays)
    print3(offsets, "before");
    add_bias(offsets, 0.050F, 0.000F, -0.020F);
    clamp3(offsets, -1.000F, 1.000F);
    print3(offsets, "after");
}

} // namespace accel_011_nc

int main() {
    using namespace accel_011_nc;
    float accel_offsets[3] = {0.000F, 0.000F, 0.000F};
    apply_calibration(accel_offsets);
    return 0;
}
