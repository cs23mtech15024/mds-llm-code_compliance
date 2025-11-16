// Context: Pressure sensor reading history

// ------ Non-Compliant Program (013_nc.cpp)
// Context: Average the first two pressure samples
// Rule: Array shall not decay — VIOLATED (pressures[] decays)
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace press_013_nc {

static float mean2(const float *v, std::size_t n) { // NC helper
    if (n < 2U) { return (n ? v[0] : 0.0F); }
    return (v[0] + v[1]) / 2.0F;
}

static void dump_head(const float *v, std::size_t n) { // NC helper
    std::cout << "head:";
    for (std::size_t i = 0; i < n && i < 4U; ++i) { std::cout << ' ' << v[i]; }
    std::cout << "\n";
}

float calculate_average(float pressures[]) { // NC API
    dump_head(pressures, 50U);
    return mean2(pressures, 50U);
}

} // namespace press_013_nc

int main() {
    using namespace press_013_nc;
    float pressure_log[50] = {101.3F, 101.5F, 101.6F, 101.4F};
    std::cout << std::fixed << std::setprecision(2)
              << "avg=" << calculate_average(pressure_log) << "\n";
    return 0;
}
