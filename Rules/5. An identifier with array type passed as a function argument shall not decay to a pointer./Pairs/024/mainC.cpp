// Context: Touchscreen calibration points

// ------ Compliant Program (024_c.cpp)
// Context: Touchscreen calibration modifies first point's X
// Status: COMPLIANT (array by reference)
#include <iostream>

namespace touch_024_c {

static void clamp(int &v, int lo, int hi) {
    if (v < lo) v = lo; else if (v > hi) v = hi;
}

void calibrate_touch(int (&cal_points)[6]) { // C API
    cal_points[0] = 100;
    clamp(cal_points[0], 0, 1023);
    std::cout << "point0_x=" << cal_points[0] << "\n";
}

} // namespace touch_024_c

int main() {
    using namespace touch_024_c;
    int touch_cal[6] = {0};
    calibrate_touch(touch_cal);
    return 0;
}
