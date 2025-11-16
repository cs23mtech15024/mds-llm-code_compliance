// Context: Drone flight PID tuning parameters

// -------- Compliant Program (prog_005_c.cpp)
// Context: Drone PID tuning — COMPLIANT
#include <iostream>
#include <iomanip>
#include <cstddef>
#include "seedC.h"

// Definitions
float seed005_kp = 1.1F;
float seed005_ki = 0.03F;
float seed005_kd = 0.55F;
float seed005_pid(float e) { return seed005_kp * e; }

namespace pid_c {

template <typename T>
T compute_derivative(T e_curr, T e_prev) {
    return (e_curr - e_prev) * seed005_kd;
}

template <typename T>
T compute_integral(T acc, T e) {
    return acc + (e * seed005_ki);
}

template <std::size_t N>
void run_pid(const float (&e)[N]) {
    double integral = 0.0;
    double prev = e[0];
    for (std::size_t i = 0; i < N; ++i) {
        integral = compute_integral(integral, e[i]);
        double d = compute_derivative(e[i], prev);
        double out = seed005_pid(e[i]) + d + integral;
        prev = e[i];
        std::cout << "step=" << i << " output=" << out << "\n";
    }
}

} // namespace pid_c

int main() {
    using namespace pid_c;
    const float err[5] = {0.2F, 0.1F, -0.05F, -0.1F, 0.0F};
    run_pid(err);
    return 0;
}
