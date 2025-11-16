// Context: Satellite orbital elements

// ------ Non-Compliant Program (082_nc.cpp)
// Context: Satellite orbital elements (a,e,i,Ω,ω,ν)
// Rule: Array parameter decays to pointer (VIOLATION)
// Risk: Wrong-sized buffers compile and call
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace orbit_082_nc {

// Force a circular-ish orbit if a is too small
static void ensure_semimajor(double *elts, std::size_t n){ if(n>0U && elts[0] < 6600.0){ elts[0] = 7000.0; } }

// NC: elements[] loses the bound 6 at the interface
void tune_elements(double elements[]) { // NC API
    const std::size_t N = 6U; (void)N;
    ensure_semimajor(elements, 6U);
    elements[1] = 0.0012;            // eccentricity
    double inc_deg = 97.6;           // inclination example
    // tiny report
    std::cout << std::fixed << std::setprecision(4)
              << "a[km]=" << elements[0]
              << ", e=" << elements[1]
              << ", i=" << inc_deg << "\n";
}

// Head preview utility
static void dump3(const double *e){
    for(int i=0;i<3;i++){ std::cout << (i?",":"head:") << e[i]; }
    std::cout << "\n";
}

} // namespace orbit_082_nc

int main(){
    using namespace orbit_082_nc;
    double el[6] = {6578.0, 0.0, 97.5, 0.0, 0.0, 0.0};
    tune_elements(el);
    dump3(el);
    return 0;
}
