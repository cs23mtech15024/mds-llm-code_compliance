// Context: Suspension damper coefficients

// ------ Non-Compliant Program (077_nc.cpp)
// Context: Suspension damper coefficients
// Rule: Array parameter decays to pointer (VIOLATION)
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace sus_077_nc {

static void set_first(float *c, std::size_t n, float v){ if (n>0U) c[0]=v; }

void adjust_suspension(float coeffs[]) { // NC API
    const std::size_t N = 4U; (void)N;
    set_first(coeffs, 4U, 1200.0F);
    std::cout << std::fixed << std::setprecision(1)
              << "damper0=" << coeffs[0] << "\n";
}

} // namespace sus_077_nc

int main(){
    using namespace sus_077_nc;
    float damper_coeffs[4] = {0.0F, 800.0F, 900.0F, 1000.0F};
    adjust_suspension(damper_coeffs);
    for (int i=0;i<4;i++){ std::cout << (i?",":"coef:") << damper_coeffs[i]; }
    std::cout << "\n";
    return 0;
}
