// Context: Power supply rail voltages

// ------ Non-Compliant Program (062_nc.cpp)
// Context: Power rail validation + quick stats
// Rule: Array parameter decays to pointer (VIOLATED)
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace rails_062_nc {

constexpr std::size_t kRails = 4U;

static bool within(float v, float lo, float hi) { return (v >= lo) && (v <= hi); }

static float average2(const float *v, std::size_t n) { // NC helper
    return (n >= 2U) ? (v[0] + v[1]) / 2.0F : 0.0F;
}

static float delta12(const float *v, std::size_t n) { // NC helper
    return (n >= 2U) ? (v[1] - v[0]) : 0.0F;
}

bool validate_power_rails(float voltages[]) { // NC API
    bool ok33 = within(voltages[0], 3.0F, 3.6F);
    bool ok50 = within(voltages[1], 4.75F, 5.25F);
    std::cout << std::fixed << std::setprecision(2)
              << "avg01=" << average2(voltages, kRails)
              << " delta10=" << delta12(voltages, kRails) << "\n";
    return ok33 && ok50;
}

} // namespace rails_062_nc

int main() {
    using namespace rails_062_nc;
    float rails[kRails] = {3.30F, 5.02F, 12.10F, -12.05F};
    std::cout << std::boolalpha << "valid=" << validate_power_rails(rails) << "\n";
    return 0;
}
