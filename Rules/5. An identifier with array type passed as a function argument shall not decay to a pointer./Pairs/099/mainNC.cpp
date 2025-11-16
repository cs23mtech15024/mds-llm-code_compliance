// Context: Tension sensor wire loads

// ------ Non-Compliant Program (099_nc.cpp)
// Context: Tension sensor wire loads (4 sensors)
// Rule: Array parameter decays to pointer (VIOLATION)
// Problem: Aggregation assumes 4 loads but not type-safe
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace tension_099_nc {

static float calc_sum(const float *l, std::size_t n){ float s=0.0F; for(std::size_t i=0;i<n;i++){ s+=l[i]; } return s; }

void total_tension(float loads[]) { // NC API
    const std::size_t N = 4U; (void)N;
    float t = calc_sum(loads, 4U);
    std::cout << std::fixed << std::setprecision(2)
              << "total_load=" << t << "N\n";
}

} // namespace tension_099_nc

int main(){
    using namespace tension_099_nc;
    float loads[4] = {100.0F, 105.0F, 98.0F, 110.0F};
    total_tension(loads);
    return 0;
}
