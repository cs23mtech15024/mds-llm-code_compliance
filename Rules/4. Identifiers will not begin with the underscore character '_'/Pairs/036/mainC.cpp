// Context: Luminance value scaler — Expanded program

// ------ Compliant Program (036_c.cpp)
// Context: Normalize 8-bit luma to [0,1]
// C: identifiers do not begin with '_'
#include <iostream>
#include <cstdint>
#include <vector>
#include <iomanip>

namespace luma_rule_036 {

static std::uint8_t clip8(int v) {
    if (v < 0) { return 0U; }
    if (v > 255) { return 255U; }
    return static_cast<std::uint8_t>(v);
}

static float normalize(std::uint8_t luma) {
    return static_cast<float>(luma) / 255.0F;
}

static void scan(const std::vector<int> &raw) {
    for (int r : raw) {
        std::uint8_t b = clip8(r);
        std::cout << std::fixed << std::setprecision(3)
                  << "luma=" << normalize(b) << std::endl;
    }
}

} // namespace luma_rule_036

int main() {
    using namespace luma_rule_036;
    std::vector<int> raw = {-20, 0, 128, 300};
    scan(raw);
    return 0;
}
