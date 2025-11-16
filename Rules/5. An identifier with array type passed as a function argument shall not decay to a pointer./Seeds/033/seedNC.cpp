// Context: Strain gauge bridge readings

// Seed 033 — NC: strain readings decay to pointer
#include <iostream>
float calculate_strain(float bridge_values[]) { // NC
    return bridge_values[0] * 0.001F;
}
int main(){
    float strain_data[4] = {1500.0F};
    std::cout << "strain=" << calculate_strain(strain_data) << "\n";
    return 0;
}