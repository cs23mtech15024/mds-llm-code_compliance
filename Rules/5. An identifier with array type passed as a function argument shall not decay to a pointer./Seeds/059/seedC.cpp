// Context: HVAC zone temperature setpoints

// Seed 059 — C: setpoints by reference
#include <iostream>
void configure_zones(float (&setpoints)[10]) { // C
    setpoints[0] = 22.0F;
    std::cout << "zone0_sp=" << setpoints[0] << "\n";
}
int main(){
    float hvac_setpoints[10] = {0};
    configure_zones(hvac_setpoints);
    return 0;
}