// Context: Particle filter weight array

// ------ Non-Compliant Program (075_nc.cpp)
// Context: Particle filter weight array
// Rule: Array parameter decays to pointer (VIOLATION)
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace pf_075_nc {

static void normalize_first(float *w, std::size_t n) { // NC helper
    if (n>0U) { w[0] = w[0] / 100.0F; }
}

void resample_particles(float weights[]) { // NC API
    const std::size_t N = 500U; (void)N;
    normalize_first(weights, 500U);
    std::cout << std::fixed << std::setprecision(4)
              << "weight0=" << weights[0] << "\n";
}

} // namespace pf_075_nc

int main(){
    using namespace pf_075_nc;
    float particle_weights[500] = {1.0F};
    resample_particles(particle_weights);
    for (int i=0;i<2;i++){ std::cout << (i?",":"head:") << particle_weights[i]; }
    std::cout << "\n";
    return 0;
}
