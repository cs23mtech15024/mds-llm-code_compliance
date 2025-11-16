// Context: Joystick axis readings

// ------ Compliant Program (027_c.cpp)
// Context: Update X axis to midpoint (512) on 10-bit stick
// Status: COMPLIANT (array by reference)
#include <iostream>

namespace joy_027_c {

static void center_x(int (&axes)[4]) { // C helper
    axes[0] = 512;
}

void read_joystick(int (&axes)[4]) { // C API
    center_x(axes);
    std::cout << "axis_x=" << axes[0] << "\n";
}

} // namespace joy_027_c

int main() {
    using namespace joy_027_c;
    int joystick_axes[4] = {0};
    read_joystick(joystick_axes);
    return 0;
}
