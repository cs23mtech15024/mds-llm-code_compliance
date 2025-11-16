// Context: pH sensor calibration values

// Seed 026 — NC: pH calibration decays to pointer
#include <iostream>
void store_ph_calibration(float ph_values[]) { // NC
    ph_values[0] = 7.0F;
    std::cout << "ph_neutral=" << ph_values[0] << "\n";
}
int main(){
    float ph_cal[3] = {0};
    store_ph_calibration(ph_cal);
    return 0;
}