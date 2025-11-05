// Context: Checksum verification routine — Expanded program

// ------ Compliant Program (013_c.cpp)
// Context: XOR checksum verifier
// C: identifiers do not begin with '_'
#include <iostream>
#include <cstdint>
#include <vector>

namespace chk_rule_013 {

static std::uint8_t xorAll(const std::vector<std::uint8_t> &data) {
    std::uint8_t x = 0U;
    for (auto b : data) { x ^= b; }
    return x;
}

static bool verify_checksum(std::uint8_t data, std::uint8_t check) {
    return static_cast<std::uint8_t>(data ^ 0xFFU) == check;
}

static void demo() {
    std::vector<std::uint8_t> v = {0xABU, 0x54U};
    std::uint8_t c1 = xorAll(v);
    bool ok = verify_checksum(0xABU, 0x54U);
    std::cout << "xor=0x" << std::hex << static_cast<unsigned>(c1)
              << " ok=" << std::dec << ok << std::endl;
}

} // namespace chk_rule_013

int main() {
    using namespace chk_rule_013;
    demo();
    return 0;
}
