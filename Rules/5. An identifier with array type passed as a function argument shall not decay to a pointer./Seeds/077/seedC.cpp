// Context: Suspension damper coefficients

// Seed 077 — C: damper coefficients by reference
#include <iostream>
void adjust_suspension(float (&coeffs)[4]) { // C
    coeffs[0] = 1200.0F;
    std::cout << "damper0=" << coeffs[0] << "\n";
}
int main(){
    float damper_coeffs[4] = {0};
    adjust_suspension(damper_coeffs);
    return 0;
}