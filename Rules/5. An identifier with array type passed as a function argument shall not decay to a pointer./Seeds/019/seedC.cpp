// Context: Servo position command array

// Seed 019 — C: servo positions by reference
#include <iostream>
void set_servo_positions(int (&positions)[16]) { // C
    positions[0] = 90;
    std::cout << "servo0=" << positions[0] << "\n";
}
int main(){
    int servo_angles[16] = {0};
    set_servo_positions(servo_angles);
    return 0;
}