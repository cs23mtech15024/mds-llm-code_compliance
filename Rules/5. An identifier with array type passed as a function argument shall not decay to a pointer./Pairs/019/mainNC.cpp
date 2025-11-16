// Context: Servo position command array

// ------ Non-Compliant Program (019_nc.cpp)
// Context: Set first servo to 90 degrees with clamping
// Rule: Array shall not decay — VIOLATED (positions[] decays)
#include <iostream>
#include <cstddef>

namespace servo_019_nc {

static void clamp(int &v, int lo, int hi) { if (v < lo) v = lo; else if (v > hi) v = hi; }

static void write_first(int *a, std::size_t n, int v) { // NC helper
    if (n > 0U) { a[0] = v; }
}

static void dump4(const int *a) { // NC helper
    std::cout << "first4:" << ' ' << a[0] << ' ' << a[1] << ' ' << a[2] << ' ' << a[3] << "\n";
}

void set_servo_positions(int positions[]) { // NC API
    const std::size_t N = 16U;
    write_first(positions, N, 90);
    clamp(positions[0], 0, 180);
    dump4(positions);
    std::cout << "servo0=" << positions[0] << "\n";
}

} // namespace servo_019_nc

int main() {
    using namespace servo_019_nc;
    int servo_angles[16] = {0};
    set_servo_positions(servo_angles);
    return 0;
}
