// Context: Mass spectrometry peak intensities

// ------ Non-Compliant Program (097_nc.cpp)
// Context: Mass spectrometry peak intensities (500 peaks)
// Rule: Array parameter decays to pointer (VIOLATION)
// Issue: Function assumes 500 peaks but not enforced by type
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace ms_097_nc {

static void normalize(float *p, std::size_t n){ float maxv = 1.0F; for(std::size_t i=0;i<n;i++){ if(p[i]>maxv) maxv=p[i]; } for(std::size_t i=0;i<n;i++){ p[i]/=maxv; } }

void identify_compound(float intensities[]) { // NC API
    const std::size_t N = 500U; (void)N;
    normalize(intensities, 500U);
    std::cout << std::fixed << std::setprecision(3)
              << "base_peak=" << intensities[0] << "\n";
}

} // namespace ms_097_nc

int main(){
    using namespace ms_097_nc;
    float peaks[500] = {};
    for(int i=0;i<500;i++){ peaks[i] = static_cast<float>((i*7)%1000)/1000.0F; }
    identify_compound(peaks);
    return 0;
}
