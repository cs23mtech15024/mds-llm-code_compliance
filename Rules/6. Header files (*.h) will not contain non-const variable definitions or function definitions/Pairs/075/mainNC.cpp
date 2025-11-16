// Context: Agricultural soil nutrient factor header

// -------- Non-Compliant Program (prog_075_nc.cpp)
#include <iostream>
#include "seedNC.h" // seed075_nutrient_factor, seed075_adjust()

namespace ag_nc {

void adjust(float bases[], std::size_t n) { // NC
    for (std::size_t i=0;i<n;++i) {
        float out = seed075_adjust(bases[i]);
        std::cout << "base=" << bases[i]
                  << " factor=" << seed075_nutrient_factor
                  << " out=" << out << "\n";
    }
}

float avg(float a[], std::size_t n){ float s=0; for(size_t i=0;i<n;++i) s+=a[i]; return n? s/n : 0; }

} // namespace ag_nc

int main(){
    using namespace ag_nc;
    float base[4] = {10.0F, 12.5F, 8.0F, 15.0F};
    adjust(base,4);
    std::cout << "avg=" << avg(base,4) << "\n";
    return 0;
}
