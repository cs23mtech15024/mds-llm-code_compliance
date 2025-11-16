// Context: Gear shift pattern map

// ------ Compliant Program (074_c.cpp)
// Context: Gear shift pattern map
// Status: Array passed by reference (COMPLIANT)
#include <iostream>

namespace shift_074_c {

static int choose_first(const int (&rpm)[6]) { return rpm[0]; }

void calculate_shift_point(int (&rpm_thresholds)[6]) { // C API
    std::cout << "shift_rpm=" << choose_first(rpm_thresholds) << "\n";
}

} // namespace shift_074_c

int main(){
    using namespace shift_074_c;
    int shift_map[6] = {2000, 3500, 5000, 0, 0, 0};
    calculate_shift_point(shift_map);
    for (int i=0;i<3;i++){ std::cout << (i?",":"head:") << shift_map[i]; }
    std::cout << "\n";
    return 0;
}
