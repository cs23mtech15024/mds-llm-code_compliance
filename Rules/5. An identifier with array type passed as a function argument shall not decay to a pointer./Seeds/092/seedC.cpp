// Context: Turbine blade stress measurements

// Seed 092 — C: stress values by reference
#include <iostream>
float find_max_stress(float (&stresses)[50]) { // C
    return stresses[0];
}
int main(){
    float blade_stress[50] = {450.0F};
    std::cout << "max_stress=" << find_max_stress(blade_stress) << "\n";
    return 0;
}