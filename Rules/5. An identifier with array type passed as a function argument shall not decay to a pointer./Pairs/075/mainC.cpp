// Context: Particle filter weight array

// ------ Compliant Program (075_c.cpp)
// Context: Particle filter weight array
// Status: Array passed by reference (COMPLIANT)
#include <iostream>
#include <iomanip>

namespace pf_075_c {

static void normalize_first(float (&w)[500]) { // C helper
    w[0] = w[0] / 100.0F;
}

void resample_particles(float (&weights)[500]) { // C API
    normalize_first(weights);
    std::cout << std::fixed << std::setprecision(4)
              << "weight0=" << weights[0] << "\n";
}

} // namespace pf_075_c

int main(){
    using namespace pf_075_c;
    float particle_weights[500] = {1.0F};
    resample_particles(particle_weights);
    for (int i=0;i<2;i++){ std::cout << (i?",":"head:") << particle_weights[i]; }
    std::cout << "\n";
    return 0;
}
