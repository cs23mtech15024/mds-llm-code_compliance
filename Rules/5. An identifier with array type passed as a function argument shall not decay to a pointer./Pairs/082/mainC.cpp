// Context: Satellite orbital elements

// ------ Compliant Program (082_c.cpp)
// Context: Satellite orbital elements (a,e,i,Ω,ω,ν)
// Status: Array passed by reference (COMPLIANT)
// Gain: Compile-time size guarantee of 6
#include <iostream>
#include <iomanip>

namespace orbit_082_c {

static void ensure_semimajor(double (&elts)[6]){ if(elts[0] < 6600.0){ elts[0] = 7000.0; } }

void tune_elements(double (&elements)[6]) { // C API
    ensure_semimajor(elements);
    elements[1] = 0.0012;            // e
    double inc_deg = 97.6;           // i
    std::cout << std::fixed << std::setprecision(4)
              << "a[km]=" << elements[0]
              << ", e=" << elements[1]
              << ", i=" << inc_deg << "\n";
}

static void dump3(const double (&e)[6]){
    for(int i=0;i<3;i++){ std::cout << (i?",":"head:") << e[i]; }
    std::cout << "\n";
}

} // namespace orbit_082_c

int main(){
    using namespace orbit_082_c;
    double el[6] = {6578.0, 0.0, 97.5, 0.0, 0.0, 0.0};
    tune_elements(el);
    dump3(el);
    return 0;
}
