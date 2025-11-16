// Context: Power supply rail voltages

// Seed 062 — C: rail voltages by reference
#include <iostream>
bool validate_power_rails(float (&voltages)[4]) { // C
    return voltages[0] > 3.0F && voltages[0] < 3.6F;
}
int main(){
    float rail_voltages[4] = {3.3F, 5.0F, 12.0F};
    std::cout << "valid=" << validate_power_rails(rail_voltages) << "\n";
    return 0;
}