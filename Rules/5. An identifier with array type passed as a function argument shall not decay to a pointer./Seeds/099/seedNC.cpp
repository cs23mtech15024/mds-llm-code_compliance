// Context: Tension sensor wire loads

// Seed 099 — NC: wire loads decay to pointer
#include <iostream>
float calculate_total_tension(float loads[]) { // NC
    return loads[0] + loads[1] + loads[2];
}
int main(){
    float wire_tensions[4] = {100.0F, 105.0F, 98.0F};
    std::cout << "total=" << calculate_total_tension(wire_tensions) << "\n";
    return 0;
}