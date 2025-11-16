// Context: Solar panel current measurements

// Seed 035 — C: current array by reference
#include <iostream>
float sum_panel_currents(float (&currents)[6]) { // C
    return currents[0] + currents[1];
}
int main(){
    float panel_currents[6] = {5.2F, 5.5F};
    std::cout << "total_current=" << sum_panel_currents(panel_currents) << "\n";
    return 0;
}