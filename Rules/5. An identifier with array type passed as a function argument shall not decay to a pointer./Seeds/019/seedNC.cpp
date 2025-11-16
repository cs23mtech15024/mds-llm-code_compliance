// Context: Servo position command array

// Seed 019 — NC: servo positions decay to pointer
#include <iostream>
void set_servo_positions(int positions[]) { // NC
    positions[0] = 90;
    std::cout << "servo0=" << positions[0] << "\n";
}
int main(){
    int servo_angles[16] = {0};
    set_servo_positions(servo_angles);
    return 0;
}