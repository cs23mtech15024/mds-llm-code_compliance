// Context: Antenna beamforming phase shifts

// ------ Non-Compliant Program (084_nc.cpp)
// Context: Antenna beamforming phase shifts (32 elements)
// Rule: Array parameter decays to pointer (VIOLATION)
// Consequence: Size assumptions live in comments, not types
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace beam_084_nc {

static float wrap_deg(float d){ while(d>=360.0F) d-=360.0F; while(d<0.0F) d+=360.0F; return d; }

static void set_steer(float *p, std::size_t n){ if(n>0U){ p[0] = wrap_deg(45.0F); } }

void compute_pattern(float phases[]) { // NC API
    const std::size_t N = 32U; (void)N;
    set_steer(phases, 32U);
    float sum = 0.0F;
    for(int i=0;i<8;i++){ sum += phases[i]; }
    std::cout << std::fixed << std::setprecision(1)
              << "phi0=" << phases[0] << ", sum8=" << sum << "\n";
}

static void head(const float *p){
    for(int i=0;i<8;i++){ std::cout << (i?",":"head:") << p[i]; }
    std::cout << "\n";
}

} // namespace beam_084_nc

int main(){
    using namespace beam_084_nc;
    float ph[32] = {};
    for(int i=0;i<32;i++){ ph[i] = wrap_deg(static_cast<float>(i*12)); }
    compute_pattern(ph);
    head(ph);
    return 0;
}
