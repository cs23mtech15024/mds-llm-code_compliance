// Context: HVAC zone temperature setpoints

// Seed 059 — NC: setpoints decay to pointer
#include <iostream>
void configure_zones(float setpoints[]) { // NC
    setpoints[0] = 22.0F;
    std::cout << "zone0_sp=" << setpoints[0] << "\n";
}
int main(){
    float hvac_setpoints[10] = {0};
    configure_zones(hvac_setpoints);
    return 0;
}