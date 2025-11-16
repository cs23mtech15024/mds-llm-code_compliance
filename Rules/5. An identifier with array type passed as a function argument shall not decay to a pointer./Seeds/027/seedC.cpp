// Context: Joystick axis readings

// Seed 027 — C: joystick axis array by reference
#include <iostream>
void read_joystick(int (&axes)[4]) { // C
    axes[0] = 512;
    std::cout << "axis_x=" << axes[0] << "\n";
}
int main(){
    int joystick_axes[4] = {0};
    read_joystick(joystick_axes);
    return 0;
}