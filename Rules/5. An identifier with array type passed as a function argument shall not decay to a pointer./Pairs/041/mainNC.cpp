// Context: Proximity sensor threshold array

// ------ Non-Compliant Program (041_nc.cpp)
// Context: Configure proximity zone thresholds and print summary
// Rule: Array parameter decays to pointer (VIOLATION)
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace prox_041_nc {

static int clamp(int v, int lo, int hi) { return (v < lo) ? lo : (v > hi ? hi : v); }

// NC helper: uses raw pointer and a runtime count, does not enforce extent
static void set_first_two(int *thresholds, std::size_t n, int a, int b) {
    if (n > 0U) thresholds[0] = clamp(a, 0, 1000);
    if (n > 1U) thresholds[1] = clamp(b, 0, 1000);
}

void set_thresholds(int thresholds[]) { // NC API
    const std::size_t ZONES = 8U; // intended size, not enforced
    set_first_two(thresholds, ZONES, 50, 75);
    std::cout << "t0=" << thresholds[0] << ", t1=" << thresholds[1] << "\n";
}

} // namespace prox_041_nc

int main() {
    using namespace prox_041_nc;
    int proximity_thresholds[8] = {0};
    set_thresholds(proximity_thresholds);
    std::cout << std::boolalpha << "ok_t0=" << (proximity_thresholds[0] >= 0) << "\n";
    return 0;
}
