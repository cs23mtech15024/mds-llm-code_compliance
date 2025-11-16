// Context: Radiation dosimeter readings

// Seed 095 — NC: dose readings decay to pointer
#include <iostream>
float calculate_cumulative_dose(float doses[]) { // NC
    return doses[0] + doses[1];
}
int main(){
    float dose_readings[100] = {0.05F, 0.06F};
    std::cout << "total_dose=" << calculate_cumulative_dose(dose_readings) << "\n";
    return 0;
}