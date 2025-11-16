// Context: Clutch engagement pressure curve

// ------ Compliant Program (098_c.cpp)
// Context: Clutch engagement pressure curve (20 points)
// Status: Array passed by reference (COMPLIANT)
// Benefit: Enforced compile-time 20-element array
#include <iostream>
#include <iomanip>

namespace clutch_098_c {

static void adjust_first(float (&p)[20]){ p[0] = 25.0F; }

void apply_curve(float (&pressures)[20]) { // C API
    adjust_first(pressures);
    float total = 0.0F;
    for(int i=0;i<20;i++){ total += pressures[i]; }
    float avg = total/20.0F;
    std::cout << std::fixed << std::setprecision(2)
              << "p0=" << pressures[0] << ", avg=" << avg << "\n";
}

} // namespace clutch_098_c

int main(){
    using namespace clutch_098_c;
    float curve[20] = {};
    for(int i=0;i<20;i++){ curve[i] = 10.0F + static_cast<float>(i); }
    apply_curve(curve);
    return 0;
}
