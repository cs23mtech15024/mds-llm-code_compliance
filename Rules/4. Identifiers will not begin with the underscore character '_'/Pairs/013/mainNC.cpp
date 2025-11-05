// Context: Checksum verification routine — Expanded program

// ------ Non-Compliant Program (013_nc.cpp)
// Context: XOR checksum verifier
// MISRA: Identifiers must not begin with '_'
// NC: function and args begin with '_'
#include <iostream>
#include <cstdint>
#include <vector>

namespace _chk_rule_013 {

static std::uint8_t _xorAll(const std::vector<std::uint8_t> &_data) {
    std::uint8_t x = 0U;
    for (auto b : _data) { x ^= b; }
    return x;
}

static bool _verify_checksum(std::uint8_t _data, std::uint8_t _check) {
    return static_cast<std::uint8_t>(_data ^ 0xFFU) == _check;
}

static void _demo() {
    std::vector<std::uint8_t> v = {0xABU, 0x54U};
    std::uint8_t c1 = _xorAll(v);
    bool ok = _verify_checksum(0xABU, 0x54U);
    std::cout << "xor=0x" << std::hex << static_cast<unsigned>(c1)
              << " ok=" << std::dec << ok << std::endl;
}

} // namespace _chk_rule_013

int main() {
    using namespace _chk_rule_013;
    _demo();
    return 0;
}
