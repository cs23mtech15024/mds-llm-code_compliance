// Context: Bit mask generator — Expanded program

// ------ Compliant Program (032_c.cpp)
// Context: Create (1<<bits)-1 mask
// C: identifiers do not begin with '_'
#include <iostream>
#include <cstdint>
#include <vector>
#include <iomanip>

namespace mask_rule_032 {

static int sanitizeBits(int b) {
    if (b < 0) { return 0; }
    if (b > 31) { return 31; }
    return b;
}

static std::uint32_t create_mask(int bits) {
    int n = sanitizeBits(bits);
    if (n == 0) { return 0U; }
    return static_cast<std::uint32_t>((1U << static_cast<unsigned>(n)) - 1U);
}

static void table(const std::vector<int> &vals) {
    for (int b : vals) {
        std::uint32_t m = create_mask(b);
        std::cout << "bits=" << b << " mask=0x" << std::hex
                  << std::setw(8) << std::setfill('0') << m << std::dec << std::endl;
    }
}

} // namespace mask_rule_032

int main() {
    using namespace mask_rule_032;
    std::vector<int> vals = {-1, 0, 1, 8, 33};
    table(vals);
    return 0;
}
