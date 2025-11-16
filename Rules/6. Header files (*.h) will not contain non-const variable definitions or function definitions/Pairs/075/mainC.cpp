// Context: Agricultural soil nutrient factor header

// -------- Compliant Program (prog_075_c.cpp)
#include <iostream>
#include "seedC.h"

float seed075_nutrient_factor = 0.72F;
float seed075_adjust(float base) { return base * seed075_nutrient_factor; }

namespace ag_c {

template <std::size_t N>
void adjust(const float (&bases)[N]){
    for(auto v:bases){
        float out = seed075_adjust(v);
        std::cout << "base=" << v
                  << " factor=" << seed075_nutrient_factor
                  << " out=" << out << "\n";
    }
}

template <std::size_t N>
float avg(const float (&a)[N]){ float s=0; for(auto v:a) s+=v; return N? s/N : 0; }

} // namespace ag_c

int main(){
    using namespace ag_c;
    const float base[4] = {10.0F, 12.5F, 8.0F, 15.0F};
    adjust(base);
    std::cout << "avg=" << avg(base) << "\n";
    return 0;
}
