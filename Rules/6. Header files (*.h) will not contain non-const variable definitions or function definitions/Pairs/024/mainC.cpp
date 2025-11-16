// Context: Motor driver header with speed variable

// -------- Compliant Program (prog_024_c.cpp)
// Context: Motor driver control — COMPLIANT
#include <iostream>
#include "seedC.h"

// Definitions
int seed024_motor_speed = 1500;
void seed024_set_speed(int s) { seed024_motor_speed = s; }

namespace motor_c {

void accelerate(int inc) {
    seed024_motor_speed += inc;
}

template <std::size_t N>
void run(const int (&speeds)[N]) {
    for (std::size_t i = 0; i < N; ++i) {
        seed024_set_speed(speeds[i]);
        accelerate(10);
        std::cout << "speed=" << seed024_motor_speed << "\n";
    }
}

template <std::size_t N>
int sum(const int (&arr)[N]) {
    int s = 0;
    for (auto v : arr) s += v;
    return s;
}

} // namespace motor_c

int main() {
    using namespace motor_c;
    const int sp[4] = {1000,1200,1400,1600};
    run(sp);
    std::cout << "sum=" << sum(sp) << "\n";
    return 0;
}
