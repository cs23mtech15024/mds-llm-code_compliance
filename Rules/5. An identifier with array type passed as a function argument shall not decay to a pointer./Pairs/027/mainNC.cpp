// Context: Joystick axis readings

// ------ Non-Compliant Program (027_nc.cpp)
// Context: Update X axis to midpoint (512) on 10-bit stick
// Status: VIOLATED (array decays)
#include <iostream>

namespace joy_027_nc {

static void center_x(int *axes) { // NC helper
    axes[0] = 512;
}

void read_joystick(int axes[]) { // NC API
    center_x(axes);
    std::cout << "axis_x=" << axes[0] << "\n";
}

} // namespace joy_027_nc

int main() {
    using namespace joy_027_nc;
    int joystick_axes[4] = {0};
    read_joystick(joystick_axes);
    return 0;
}
