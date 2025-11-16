// Context: Proximity sensor threshold array

// ------ Compliant Program (041_c.cpp)
// Context: Configure proximity zone thresholds and print summary
// Status: Array passed by reference (COMPLIANT)
#include <iostream>
#include <iomanip>

namespace prox_041_c {

static int clamp(int v, int lo, int hi) { return (v < lo) ? lo : (v > hi ? hi : v); }

static void set_first_two(int (&thresholds)[8], int a, int b) {
    thresholds[0] = clamp(a, 0, 1000);
    thresholds[1] = clamp(b, 0, 1000);
}

void set_thresholds(int (&thresholds)[8]) { // C API
    set_first_two(thresholds, 50, 75);
    std::cout << "t0=" << thresholds[0] << ", t1=" << thresholds[1] << "\n";
}

} // namespace prox_041_c

int main() {
    using namespace prox_041_c;
    int proximity_thresholds[8] = {0};
    set_thresholds(proximity_thresholds);
    std::cout << std::boolalpha << "ok_t0=" << (proximity_thresholds[0] >= 0) << "\n";
    return 0;
}
