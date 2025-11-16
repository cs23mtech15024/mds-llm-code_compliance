// Context: Load cell weight samples

// ------ Non-Compliant Program (047_nc.cpp)
// Context: Convert raw counts to kg and show formatted output
// Rule: Array parameter decays to pointer (VIOLATION)
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace lc_047_nc {

// NC helper: pointer + length, no static bound
static float to_kg_first(const float *s, std::size_t n, float scale) {
    return (n > 0U) ? (s[0] * scale) : 0.0F;
}

float calculate_weight(float samples[]) { // NC API
    return to_kg_first(samples, 32U, 0.001F);
}

} // namespace lc_047_nc

int main() {
    using namespace lc_047_nc;
    float loadcell_samples[32] = {5000.0F};
    std::cout << std::fixed << std::setprecision(3) << "weight_kg=" << calculate_weight(loadcell_samples) << "\n";
    return 0;
}
