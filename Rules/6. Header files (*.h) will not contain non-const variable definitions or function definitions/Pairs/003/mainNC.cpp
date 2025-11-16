// Context: Sensor fusion filter gains

// -------- Non-Compliant Program (prog_003_nc.cpp)
// Context: Sensor fusion filter gains
#include <iostream>
#include <cstddef>
#include "seedNC.h" // seed003_alpha, seed003_beta, seed003_filter()

namespace fusion_nc {

void apply_filters(double p[], double m[], std::size_t n) { // NC: decayed arrays
    for (std::size_t i = 0; i < n; ++i) {
        double out = seed003_filter(p[i], m[i]);
        std::cout << "filtered[" << i << "]=" << out << "\n";
    }
}

double error_metric(double vals[], std::size_t n) { // NC
    double s = 0.0;
    for (std::size_t i = 0; i < n; ++i) s += vals[i];
    return (n > 0U) ? s / n : 0.0;
}

} // namespace fusion_nc

int main() {
    using namespace fusion_nc;
    double pred[4] = {1.0, 2.0, 3.0, 4.0};
    double meas[4] = {0.8, 1.9, 3.1, 4.2};
    apply_filters(pred, meas, 4);
    std::cout << "err=" << error_metric(pred, 4) << "\n";
    return 0;
}
