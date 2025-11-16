// Context: Digital filter coefficient storage

// ------ Non-Compliant Program (016_nc.cpp)
// Context: Load first coefficient for a 64-tap FIR filter
// Rule: Array shall not decay — VIOLATED (coeffs[] decays)
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace fir_016_nc {

static void set_coeff(double *c, std::size_t i, double v) { // NC helper
    c[i] = v;
}

static void normalize(double *c, std::size_t n) { // NC helper
    double sum = 0.0; for (std::size_t i = 0; i < n; ++i) sum += c[i];
    if (sum == 0.0) return; for (std::size_t i = 0; i < n; ++i) c[i] /= sum;
}

static void show4(const double *c) { // NC helper
    std::cout << std::fixed << std::setprecision(2)
              << "head:" << c[0] << ' ' << c[1] << ' ' << c[2] << ' ' << c[3] << "\n";
}

void load_coefficients(double coeffs[]) { // NC API
    const std::size_t N = 64U;
    for (std::size_t i = 0; i < N; ++i) set_coeff(coeffs, i, (i == 0 ? 0.25 : 0.0));
    normalize(coeffs, N);
    show4(coeffs);
}

} // namespace fir_016_nc

int main() {
    using namespace fir_016_nc;
    double fir_coeffs[64] = {0.0};
    load_coefficients(fir_coeffs);
    return 0;
}
