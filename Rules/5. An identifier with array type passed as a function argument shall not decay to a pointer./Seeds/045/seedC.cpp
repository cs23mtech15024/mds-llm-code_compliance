// Context: Gas sensor PPM measurements

// Seed 045 — C: PPM values by reference
#include <iostream>
float get_average_ppm(float (&ppm_values)[20]) { // C
    return (ppm_values[0] + ppm_values[1]) / 2.0F;
}
int main(){
    float gas_ppm[20] = {150.0F, 155.0F};
    std::cout << "avg_ppm=" << get_average_ppm(gas_ppm) << "\n";
    return 0;
}