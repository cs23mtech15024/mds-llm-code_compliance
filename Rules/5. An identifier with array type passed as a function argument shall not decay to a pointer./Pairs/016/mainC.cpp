// Context: Digital filter coefficient storage

// ------ Compliant Program (016_c.cpp)
// Context: Load first coefficient for a 64-tap FIR filter
// Rule: COMPLIANT (array by reference keeps bound)
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace fir_016_c {

static void set_coeff(double (&c)[64], std::size_t i, double v) { // C helper
    c[i] = v;
}

static void normalize(double (&c)[64]) { // C helper
    double sum = 0.0; for (double v : c) sum += v;
    if (sum == 0.0) return; for (double &v : c) v /= sum;
}

static void show4(const double (&c)[64]) { // C helper
    std::cout << std::fixed << std::setprecision(2)
              << "head:" << c[0] << ' ' << c[1] << ' ' << c[2] << ' ' << c[3] << "\n";
}

void load_coefficients(double (&coeffs)[64]) { // C API
    for (std::size_t i = 0; i < 64U; ++i) set_coeff(coeffs, i, (i == 0 ? 0.25 : 0.0));
    normalize(coeffs);
    show4(coeffs);
}

} // namespace fir_016_c

int main() {
    using namespace fir_016_c;
    double fir_coeffs[64] = {0.0};
    load_coefficients(fir_coeffs);
    return 0;
}
