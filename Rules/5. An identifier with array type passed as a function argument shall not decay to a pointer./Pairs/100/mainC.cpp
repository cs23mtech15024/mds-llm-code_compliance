// Context: Brake pad wear indicator values

// ------ Compliant Program (100_c.cpp)
// Context: Brake pad wear indicator values (4 sensors)
// Status: Array passed by reference (COMPLIANT)
// Benefit: Type ensures exactly 4-sensor input
#include <iostream>
#include <iomanip>

namespace brake_100_c {

static bool any_replace(const float (&v)[4]){ for(int i=0;i<4;i++){ if(v[i]<2.0F) return true; } return false; }

void check_brake_wear(float (&wear_levels)[4]) { // C API
    bool replace = any_replace(wear_levels);
    std::cout << std::boolalpha << "needs_replacement=" << replace << "\n";
}

} // namespace brake_100_c

int main(){
    using namespace brake_100_c;
    float wear[4] = {1.5F, 2.5F, 1.8F, 2.2F};
    check_brake_wear(wear);
    return 0;
}
