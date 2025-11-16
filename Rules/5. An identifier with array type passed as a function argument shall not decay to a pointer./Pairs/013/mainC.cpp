// Context: Pressure sensor reading history

// ------ Compliant Program (013_c.cpp)
// Context: Average the first two pressure samples
// Rule: COMPLIANT (array by reference preserves bound)
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace press_013_c {

static float mean2(const float (&v)[50]) { // C helper
    return (v[0] + v[1]) / 2.0F;
}

static void dump_head(const float (&v)[50]) { // C helper
    std::cout << "head:";
    for (std::size_t i = 0; i < 4U; ++i) { std::cout << ' ' << v[i]; }
    std::cout << "\n";
}

float calculate_average(float (&pressures)[50]) { // C API
    dump_head(pressures);
    return mean2(pressures);
}

} // namespace press_013_c

int main() {
    using namespace press_013_c;
    float pressure_log[50] = {101.3F, 101.5F, 101.6F, 101.4F};
    std::cout << std::fixed << std::setprecision(2)
              << "avg=" << calculate_average(pressure_log) << "\n";
    return 0;
}
