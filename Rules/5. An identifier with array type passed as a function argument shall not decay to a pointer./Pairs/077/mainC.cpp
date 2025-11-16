// Context: Suspension damper coefficients

// ------ Compliant Program (077_c.cpp)
// Context: Suspension damper coefficients
// Status: Array passed by reference (COMPLIANT)
#include <iostream>
#include <iomanip>

namespace sus_077_c {

static void set_first(float (&c)[4], float v){ c[0]=v; }

void adjust_suspension(float (&coeffs)[4]) { // C API
    set_first(coeffs, 1200.0F);
    std::cout << std::fixed << std::setprecision(1)
              << "damper0=" << coeffs[0] << "\n";
}

} // namespace sus_077_c

int main(){
    using namespace sus_077_c;
    float damper_coeffs[4] = {0.0F, 800.0F, 900.0F, 1000.0F};
    adjust_suspension(damper_coeffs);
    for (int i=0;i<4;i++){ std::cout << (i?",":"coef:") << damper_coeffs[i]; }
    std::cout << "\n";
    return 0;
}
