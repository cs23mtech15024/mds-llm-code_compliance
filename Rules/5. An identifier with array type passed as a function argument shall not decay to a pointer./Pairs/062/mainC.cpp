// Context: Power supply rail voltages

// ------ Compliant Program (062_c.cpp)
// Context: Power rail validation + quick stats
// Rule: Array preserved by reference (COMPLIANT)
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace rails_062_c {

constexpr std::size_t kRails = 4U;

static bool within(float v, float lo, float hi) { return (v >= lo) && (v <= hi); }

template <std::size_t N>
static float average2(const float (&v)[N]) {
    static_assert(N >= 2U, "need at least two rails");
    return (v[0] + v[1]) / 2.0F;
}

template <std::size_t N>
static float delta12(const float (&v)[N]) {
    static_assert(N >= 2U, "need at least two rails");
    return (v[1] - v[0]);
}

bool validate_power_rails(float (&voltages)[kRails]) { // C API
    bool ok33 = within(voltages[0], 3.0F, 3.6F);
    bool ok50 = within(voltages[1], 4.75F, 5.25F);
    std::cout << std::fixed << std::setprecision(2)
              << "avg01=" << average2(voltages)
              << " delta10=" << delta12(voltages) << "\n";
    return ok33 && ok50;
}

} // namespace rails_062_c

int main() {
    using namespace rails_062_c;
    float rails[kRails] = {3.30F, 5.02F, 12.10F, -12.05F};
    std::cout << std::boolalpha << "valid=" << validate_power_rails(rails) << "\n";
    return 0;
}
