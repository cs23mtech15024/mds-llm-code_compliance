// Context: Bit mask generator — Expanded program

// ------ Non-Compliant Program (032_nc.cpp)
// Context: Create (1<<bits)-1 mask
// MISRA: Identifiers must not begin with '_'
// NC: function and parameter begin with '_'
#include <iostream>
#include <cstdint>
#include <vector>
#include <iomanip>

namespace _mask_rule_032 {

static int _sanitizeBits(int b) {
    if (b < 0) { return 0; }
    if (b > 31) { return 31; }
    return b;
}

static std::uint32_t _create_mask(int _bits) { // NC
    int n = _sanitizeBits(_bits);
    if (n == 0) { return 0U; }
    return static_cast<std::uint32_t>((1U << static_cast<unsigned>(n)) - 1U);
}

static void _table(const std::vector<int> &_vals) {
    for (int b : _vals) {
        std::uint32_t m = _create_mask(b);
        std::cout << "bits=" << b << " mask=0x" << std::hex
                  << std::setw(8) << std::setfill('0') << m << std::dec << std::endl;
    }
}

} // namespace _mask_rule_032

int main() {
    using namespace _mask_rule_032;
    std::vector<int> vals = {-1, 0, 1, 8, 33};
    _table(vals);
    return 0;
}
