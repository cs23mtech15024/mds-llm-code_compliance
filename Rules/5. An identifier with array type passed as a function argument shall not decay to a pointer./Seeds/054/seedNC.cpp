// Context: Actuator feedback position array

// Seed 054 — NC: positions decay to pointer
#include <iostream>
float get_actuator_position(float positions[]) { // NC
    return positions[0];
}
int main(){
    float actuator_pos[6] = {45.5F};
    std::cout << "pos0=" << get_actuator_position(actuator_pos) << "\n";
    return 0;
}