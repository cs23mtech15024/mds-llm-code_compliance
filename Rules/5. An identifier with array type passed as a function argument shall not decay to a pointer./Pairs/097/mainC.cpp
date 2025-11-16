// Context: Mass spectrometry peak intensities

// ------ Compliant Program (097_c.cpp)
// Context: Mass spectrometry peak intensities (500 peaks)
// Status: Array passed by reference (COMPLIANT)
// Benefit: Size of 500 enforced by compiler
#include <iostream>
#include <iomanip>

namespace ms_097_c {

static void normalize(float (&p)[500]){ float maxv = 1.0F; for(int i=0;i<500;i++){ if(p[i]>maxv) maxv=p[i]; } for(int i=0;i<500;i++){ p[i]/=maxv; } }

void identify_compound(float (&intensities)[500]) { // C API
    normalize(intensities);
    std::cout << std::fixed << std::setprecision(3)
              << "base_peak=" << intensities[0] << "\n";
}

} // namespace ms_097_c

int main(){
    using namespace ms_097_c;
    float peaks[500] = {};
    for(int i=0;i<500;i++){ peaks[i] = static_cast<float>((i*7)%1000)/1000.0F; }
    identify_compound(peaks);
    return 0;
}
