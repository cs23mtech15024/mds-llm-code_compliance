// Context: Battery charge cycle counters header

// -------- Compliant Program (prog_051_c.cpp)
// Context: Battery cycle counting — COMPLIANT
#include <iostream>
#include "seedC.h"

// Definitions
unsigned int seed051_cycle_count = 0;
void seed051_increment(){ ++seed051_cycle_count; }

namespace batt_c {

template <std::size_t N>
void simulate(const unsigned int (&ops)[N]) {
    for (auto v : ops) {
        for (unsigned int j=0;j<v;++j) seed051_increment();
        std::cout << "ops=" << v << " total=" << seed051_cycle_count << "\n";
    }
}

template <std::size_t N>
unsigned int sum(const unsigned int (&arr)[N]){
    unsigned int s=0; for(auto v:arr)s+=v; return s;
}

} // namespace batt_c

int main(){
    using namespace batt_c;
    const unsigned int a[4]={1,2,3,1};
    simulate(a);
    std::cout << "sum=" << sum(a) << "\n";
    return 0;
}
