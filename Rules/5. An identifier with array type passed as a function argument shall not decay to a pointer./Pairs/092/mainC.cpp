// Context: Turbine blade stress measurements

// ------ Compliant Program (092_c.cpp)
// Context: Turbine blade stress measurements (50 points)
// Status: Array passed by reference (COMPLIANT)
// Result: Compile-time guarantee of length
#include <iostream>
#include <iomanip>

namespace turbine_092_c {

static float clamp_mpa(float v){ return (v<0.0F?0.0F:(v>1200.0F?1200.0F:v)); }

static void set_probe_zero(float (&s)[50]){ s[0] = clamp_mpa(s[0]); }

void find_max_stress(float (&stresses)[50]) { // C API
    set_probe_zero(stresses);
    float mx = stresses[0];
    int idx = 0;
    for(int i=1;i<50;i++){
        if(stresses[i] > mx){ mx = stresses[i]; idx = i; }
    }
    std::cout << std::fixed << std::setprecision(2)
              << "max=" << mx << "MPa @" << idx << "\n";
}

static void print_head(const float (&s)[50]){
    for(int i=0;i<10;i++){ std::cout << (i?",":"head:") << s[i]; }
    std::cout << "\n";
}

} // namespace turbine_092_c

int main(){
    using namespace turbine_092_c;
    float stress[50] = {};
    for(int i=0;i<50;i++){ stress[i] = 400.0F + static_cast<float>((i*13)%300); }
    find_max_stress(stress);
    print_head(stress);
    return 0;
}
