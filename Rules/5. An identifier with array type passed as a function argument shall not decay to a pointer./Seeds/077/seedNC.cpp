// Context: Suspension damper coefficients

// Seed 077 — NC: damper coefficients decay to pointer
#include <iostream>
void adjust_suspension(float coeffs[]) { // NC
    coeffs[0] = 1200.0F;
    std::cout << "damper0=" << coeffs[0] << "\n";
}
int main(){
    float damper_coeffs[4] = {0};
    adjust_suspension(damper_coeffs);
    return 0;
}