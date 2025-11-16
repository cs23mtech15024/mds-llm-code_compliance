// Context: Brake pad wear indicator values

// ------ Non-Compliant Program (100_nc.cpp)
// Context: Brake pad wear indicator values (4 sensors)
// Rule: Array parameter decays to pointer (VIOLATION)
// Risk: Boolean evaluation assumes 4 values but unchecked
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace brake_100_nc {

static bool any_replace(const float *v, std::size_t n){ for(std::size_t i=0;i<n;i++){ if(v[i]<2.0F) return true; } return false; }

void check_brake_wear(float wear_levels[]) { // NC API
    const std::size_t N = 4U; (void)N;
    bool replace = any_replace(wear_levels, 4U);
    std::cout << std::boolalpha << "needs_replacement=" << replace << "\n";
}

} // namespace brake_100_nc

int main(){
    using namespace brake_100_nc;
    float wear[4] = {1.5F, 2.5F, 1.8F, 2.2F};
    check_brake_wear(wear);
    return 0;
}
