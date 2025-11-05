// Context: Altitude compensation factor

// Seed 022 — C: variable without underscore prefix
#include <iostream>
int main(){
    float altitude_m = 1500.0F; // C
    float compensation = 1.0F - (altitude_m / 10000.0F);
    std::cout << "comp=" << compensation << "\n";
    return 0;
}