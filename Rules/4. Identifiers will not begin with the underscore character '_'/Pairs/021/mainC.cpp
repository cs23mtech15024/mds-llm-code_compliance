// Context: CRC polynomial generator — Expanded program

// ------ Compliant Program (021_c.cpp)
// Context: Simple 8-bit CRC-like demo (toy)
// C: no identifiers begin with '_'
#include <iostream>
#include <cstdint>
#include <vector>
#include <iomanip>

namespace crc_rule_021 {

static std::uint8_t scramble(std::uint8_t x) {
    x ^= static_cast<std::uint8_t>((x << 3U) | (x >> 5U));
    x ^= 0x5AU;
    return x;
}

static std::uint16_t compute_crc(std::uint8_t data) { // C
    std::uint8_t s = scramble(data);
    return static_cast<std::uint16_t>(static_cast<std::uint16_t>(s) ^ 0x00FFU);
}

static void printSeq(const std::vector<std::uint8_t> &v) {
    for (auto b : v) {
        std::uint16_t c = compute_crc(b);
        std::cout << "b=0x" << std::hex << std::setw(2) << std::setfill('0')
                  << static_cast<unsigned>(b)
                  << " crc=0x" << std::setw(4) << c << std::dec << std::endl;
    }
}

} // namespace crc_rule_021

int main() {
    using namespace crc_rule_021;
    std::vector<std::uint8_t> data;
    data.push_back(0x00U);
    data.push_back(0xABU);
    data.push_back(0xFFU);
    printSeq(data);
    return 0;
}
