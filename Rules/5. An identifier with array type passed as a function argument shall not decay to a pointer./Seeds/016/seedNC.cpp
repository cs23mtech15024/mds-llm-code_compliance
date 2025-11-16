// Context: Digital filter coefficient storage

// Seed 016 — NC: coefficient array decays to pointer
#include <iostream>
void load_coefficients(double coeffs[]) { // NC
    coeffs[0] = 0.25;
    std::cout << "coeff0=" << coeffs[0] << "\n";
}
int main(){
    double fir_coeffs[64] = {0};
    load_coefficients(fir_coeffs);
    return 0;
}