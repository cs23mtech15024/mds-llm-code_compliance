// Context: Thermal printer heat pulse configuration

// -------- Non-Compliant Program (prog_042_nc.cpp)
// Context: Thermal printer pulse timing
#include <iostream>
#include "seedNC.h" // seed042_pulse_width_us, seed042_calc_total()

namespace print_nc {

void simulate(int pulses[], std::size_t n) { // NC
    for (std::size_t i=0;i<n;++i) {
        int t = seed042_calc_total(pulses[i]);
        std::cout << "p=" << pulses[i]
                  << " width=" << seed042_pulse_width_us
                  << " total=" << t << "\n";
    }
}

int sum(int arr[], std::size_t n){int s=0;for(size_t i=0;i<n;++i)s+=arr[i];return s;}

} // namespace print_nc

int main(){
    using namespace print_nc;
    int p[4]={1,2,3,5};
    simulate(p,4);
    std::cout << "sum=" << sum(p,4) << "\n";
    return 0;
}
