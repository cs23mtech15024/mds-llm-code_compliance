// Context: Antenna beamforming phase shifts

// ------ Compliant Program (084_c.cpp)
// Context: Antenna beamforming phase shifts (32 elements)
// Status: Array passed by reference (COMPLIANT)
// Advantage: Compile-time enforcement of 32-length array
#include <iostream>
#include <iomanip>

namespace beam_084_c {

static float wrap_deg(float d){ while(d>=360.0F) d-=360.0F; while(d<0.0F) d+=360.0F; return d; }

static void set_steer(float (&p)[32]){ p[0] = wrap_deg(45.0F); }

void compute_pattern(float (&phases)[32]) { // C API
    set_steer(phases);
    float sum = 0.0F;
    for(int i=0;i<8;i++){ sum += phases[i]; }
    std::cout << std::fixed << std::setprecision(1)
              << "phi0=" << phases[0] << ", sum8=" << sum << "\n";
}

static void head(const float (&p)[32]){
    for(int i=0;i<8;i++){ std::cout << (i?",":"head:") << p[i]; }
    std::cout << "\n";
}

} // namespace beam_084_c

int main(){
    using namespace beam_084_c;
    float ph[32] = {};
    for(int i=0;i<32;i++){ ph[i] = wrap_deg(static_cast<float>(i*12)); }
    compute_pattern(ph);
    head(ph);
    return 0;
}
