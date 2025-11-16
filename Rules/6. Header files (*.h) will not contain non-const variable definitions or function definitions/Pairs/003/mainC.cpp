// Context: Sensor fusion filter gains

// -------- Compliant Program (prog_003_c.cpp)
// Context: Sensor fusion filter gains — COMPLIANT
#include <iostream>
#include <cstddef>
#include "seedC.h"

// Definitions
double seed003_alpha = 0.98;
double seed003_beta  = 0.02;
double seed003_filter(double p, double m) { return seed003_alpha * p + seed003_beta * m; }

namespace fusion_c {

template <std::size_t N>
void apply_filters(const double (&p)[N], const double (&m)[N]) {
    for (std::size_t i = 0; i < N; ++i) {
        double out = seed003_filter(p[i], m[i]);
        std::cout << "filtered[" << i << "]=" << out << "\n";
    }
}

template <std::size_t N>
double error_metric(const double (&vals)[N]) {
    double s = 0.0;
    for (double v : vals) s += v;
    return (N > 0U) ? s / N : 0.0;
}

} // namespace fusion_c

int main() {
    using namespace fusion_c;
    const double pred[4] = {1.0, 2.0, 3.0, 4.0};
    const double meas[4] = {0.8, 1.9, 3.1, 4.2};
    apply_filters(pred, meas);
    std::cout << "err=" << error_metric(pred) << "\n";
    return 0;
}
