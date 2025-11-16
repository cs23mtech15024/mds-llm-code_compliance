// Context: Gear shift pattern map

// Seed 074 — NC: shift map decays to pointer
#include <iostream>
void calculate_shift_point(int rpm_thresholds[]) { // NC
    std::cout << "shift_rpm=" << rpm_thresholds[0] << "\n";
}
int main(){
    int shift_map[6] = {2000, 3500, 5000};
    calculate_shift_point(shift_map);
    return 0;
}