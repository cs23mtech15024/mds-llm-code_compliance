// Context: Gear shift pattern map

// ------ Non-Compliant Program (074_nc.cpp)
// Context: Gear shift pattern map
// Rule: Array parameter decays to pointer (VIOLATION)
#include <iostream>
#include <cstddef>

namespace shift_074_nc {

static int choose_first(const int *rpm, std::size_t n) { // NC helper
    return (n>0U) ? rpm[0] : 0;
}

void calculate_shift_point(int rpm_thresholds[]) { // NC API
    const std::size_t N = 6U; (void)N;
    std::cout << "shift_rpm=" << choose_first(rpm_thresholds, 6U) << "\n";
}

} // namespace shift_074_nc

int main(){
    using namespace shift_074_nc;
    int shift_map[6] = {2000, 3500, 5000, 0, 0, 0};
    calculate_shift_point(shift_map);
    for (int i=0;i<3;i++){ std::cout << (i?",":"head:") << shift_map[i]; }
    std::cout << "\n";
    return 0;
}
