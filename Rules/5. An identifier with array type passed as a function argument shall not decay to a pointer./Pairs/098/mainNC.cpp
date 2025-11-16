// Context: Clutch engagement pressure curve

// ------ Non-Compliant Program (098_nc.cpp)
// Context: Clutch engagement pressure curve (20 points)
// Rule: Array parameter decays to pointer (VIOLATION)
// Risk: Bounds checking lost for 20-point curve
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace clutch_098_nc {

static void adjust_first(float *p, std::size_t n){ if(n>0U){ p[0] = 25.0F; } }

void apply_curve(float pressures[]) { // NC API
    const std::size_t N = 20U; (void)N;
    adjust_first(pressures, 20U);
    float total = 0.0F;
    for(int i=0;i<20;i++){ total += pressures[i]; }
    float avg = total/20.0F;
    std::cout << std::fixed << std::setprecision(2)
              << "p0=" << pressures[0] << ", avg=" << avg << "\n";
}

} // namespace clutch_098_nc

int main(){
    using namespace clutch_098_nc;
    float curve[20] = {};
    for(int i=0;i<20;i++){ curve[i] = 10.0F + static_cast<float>(i); }
    apply_curve(curve);
    return 0;
}
