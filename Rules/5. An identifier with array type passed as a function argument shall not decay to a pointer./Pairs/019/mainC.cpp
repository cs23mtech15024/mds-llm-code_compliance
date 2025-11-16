// Context: Servo position command array

// ------ Compliant Program (019_c.cpp)
// Context: Set first servo to 90 degrees with clamping
// Rule: COMPLIANT (array by reference keeps bound)
#include <iostream>
#include <cstddef>

namespace servo_019_c {

static void clamp(int &v, int lo, int hi) { if (v < lo) v = lo; else if (v > hi) v = hi; }

static void write_first(int (&a)[16], int v) { // C helper
    a[0] = v;
}

static void dump4(const int (&a)[16]) { // C helper
    std::cout << "first4:" << ' ' << a[0] << ' ' << a[1] << ' ' << a[2] << ' ' << a[3] << "\n";
}

void set_servo_positions(int (&positions)[16]) { // C API
    write_first(positions, 90);
    clamp(positions[0], 0, 180);
    dump4(positions);
    std::cout << "servo0=" << positions[0] << "\n";
}

} // namespace servo_019_c

int main() {
    using namespace servo_019_c;
    int servo_angles[16] = {0};
    set_servo_positions(servo_angles);
    return 0;
}
