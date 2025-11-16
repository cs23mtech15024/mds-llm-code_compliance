// Context: Drone flight PID tuning parameters

// -------- Non-Compliant Program (prog_005_nc.cpp)
// Context: Drone PID tuning
#include <iostream>
#include <iomanip>
#include <cstddef>
#include "seedNC.h" // seed005_kp, seed005_ki, seed005_kd, seed005_pid()

namespace pid_nc {

double compute_derivative(double e_curr, double e_prev) {
    return (e_curr - e_prev) * seed005_kd; // uses NC global
}

double compute_integral(double acc, double e) {
    return acc + (e * seed005_ki); // uses NC global
}

void run_pid(float e[], std::size_t n) { // NC decayed array
    double integral = 0.0;
    double prev = e[0];
    for (std::size_t i = 0; i < n; ++i) {
        integral = compute_integral(integral, e[i]);
        double d = compute_derivative(e[i], prev);
        double out = seed005_pid(e[i]) + d + integral;
        prev = e[i];
        std::cout << "step=" << i << " output=" << out << "\n";
    }
}

} // namespace pid_nc

int main() {
    using namespace pid_nc;
    float err[5] = {0.2F, 0.1F, -0.05F, -0.1F, 0.0F};
    run_pid(err, 5);
    return 0;
}
