// Context: Load cell weight samples

// ------ Compliant Program (047_c.cpp)
// Context: Convert raw counts to kg and show formatted output
// Status: Array passed by reference (COMPLIANT)
#include <iostream>
#include <iomanip>

namespace lc_047_c {

static float to_kg_first(const float (&s)[32], float scale) {
    return s[0] * scale;
}

float calculate_weight(float (&samples)[32]) { // C API
    return to_kg_first(samples, 0.001F);
}

} // namespace lc_047_c

int main() {
    using namespace lc_047_c;
    float loadcell_samples[32] = {5000.0F};
    std::cout << std::fixed << std::setprecision(3) << "weight_kg=" << calculate_weight(loadcell_samples) << "\n";
    return 0;
}
