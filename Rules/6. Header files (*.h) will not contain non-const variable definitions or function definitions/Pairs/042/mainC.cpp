// Context: Thermal printer heat pulse configuration

// -------- Compliant Program (prog_042_c.cpp)
// Context: Thermal printer pulse timing — COMPLIANT
#include <iostream>
#include "seedC.h"

// Definitions
int seed042_pulse_width_us = 220;
int seed042_calc_total(int pulses){ return pulses * seed042_pulse_width_us; }

namespace print_c {

template <std::size_t N>
void simulate(const int (&pulses)[N]) {
    for (auto p : pulses) {
        int t = seed042_calc_total(p);
        std::cout << "p=" << p
                  << " width=" << seed042_pulse_width_us
                  << " total=" << t << "\n";
    }
}

template <std::size_t N>
int sum(const int (&arr)[N]) { int s=0; for(auto v:arr) s+=v; return s; }

} // namespace print_c

int main(){
    using namespace print_c;
    const int p[4]={1,2,3,5};
    simulate(p);
    std::cout << "sum=" << sum(p) << "\n";
    return 0;
}
