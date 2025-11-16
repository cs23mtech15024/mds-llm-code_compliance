// Context: Gear shift pattern map

// Seed 074 — C: shift map by reference
#include <iostream>
void calculate_shift_point(int (&rpm_thresholds)[6]) { // C
    std::cout << "shift_rpm=" << rpm_thresholds[0] << "\n";
}
int main(){
    int shift_map[6] = {2000, 3500, 5000};
    calculate_shift_point(shift_map);
    return 0;
}