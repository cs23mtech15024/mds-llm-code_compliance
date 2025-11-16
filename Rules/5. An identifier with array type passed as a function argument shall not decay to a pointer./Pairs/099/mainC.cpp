// Context: Tension sensor wire loads

// ------ Compliant Program (099_c.cpp)
// Context: Tension sensor wire loads (4 sensors)
// Status: Array passed by reference (COMPLIANT)
// Advantage: Compiler enforces 4-element load array
#include <iostream>
#include <iomanip>

namespace tension_099_c {

static float calc_sum(const float (&l)[4]){ float s=0.0F; for(int i=0;i<4;i++){ s+=l[i]; } return s; }

void total_tension(float (&loads)[4]) { // C API
    float t = calc_sum(loads);
    std::cout << std::fixed << std::setprecision(2)
              << "total_load=" << t << "N\n";
}

} // namespace tension_099_c

int main(){
    using namespace tension_099_c;
    float loads[4] = {100.0F, 105.0F, 98.0F, 110.0F};
    total_tension(loads);
    return 0;
}
