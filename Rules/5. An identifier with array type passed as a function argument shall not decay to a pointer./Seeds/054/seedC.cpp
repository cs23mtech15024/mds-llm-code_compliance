// Context: Actuator feedback position array

// Seed 054 — C: positions by reference
#include <iostream>
float get_actuator_position(float (&positions)[6]) { // C
    return positions[0];
}
int main(){
    float actuator_pos[6] = {45.5F};
    std::cout << "pos0=" << get_actuator_position(actuator_pos) << "\n";
    return 0;
}