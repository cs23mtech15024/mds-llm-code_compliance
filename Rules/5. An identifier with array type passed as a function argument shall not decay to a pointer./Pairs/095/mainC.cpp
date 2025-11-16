// Context: Radiation dosimeter readings

// ------ Compliant Program (095_c.cpp)
// Context: Radiation dosimeter readings (100 samples)
// Status: Array passed by reference (COMPLIANT)
// Benefit: Type ensures correct length for summation
#include <iostream>
#include <iomanip>

namespace dose_095_c {

static float clamp_sievert(float v){ return (v<0.0F?0.0F:(v>10.0F?10.0F:v)); }

static void fix_first_two(float (&d)[100]){ d[0] = clamp_sievert(d[0]); d[1] = clamp_sievert(d[1]); }

void cumulative_dose(float (&doses)[100]) { // C API
    fix_first_two(doses);
    float total = 0.0F;
    for(int i=0;i<100;i++){ total += doses[i]; }
    std::cout << std::fixed << std::setprecision(3)
              << "total_Sv=" << total << "\n";
}

static void print_head(const float (&d)[100]){
    for(int i=0;i<6;i++){ std::cout << (i?",":"head:") << d[i]; }
    std::cout << "\n";
}

} // namespace dose_095_c

int main(){
    using namespace dose_095_c;
    float r[100] = {0.05F, 0.06F};
    for(int i=2;i<100;i++){ r[i] = 0.01F * static_cast<float>((i%5)+1); }
    cumulative_dose(r);
    print_head(r);
    return 0;
}
