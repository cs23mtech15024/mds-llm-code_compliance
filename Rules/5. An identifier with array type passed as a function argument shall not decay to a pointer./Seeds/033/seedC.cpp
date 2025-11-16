// Context: Strain gauge bridge readings

// Seed 033 — C: strain readings by reference
#include <iostream>
float calculate_strain(float (&bridge_values)[4]) { // C
    return bridge_values[0] * 0.001F;
}
int main(){
    float strain_data[4] = {1500.0F};
    std::cout << "strain=" << calculate_strain(strain_data) << "\n";
    return 0;
}