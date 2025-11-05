// Context: CRC polynomial generator — Expanded program

// ------ Non-Compliant Program (021_nc.cpp)
// Context: Simple 8-bit CRC-like demo (toy)
// MISRA: Identifiers must not begin with '_'
// NC: function and parameter names begin with '_'
#include <iostream>
#include <cstdint>
#include <vector>
#include <iomanip>

namespace _crc_rule_021 {

static std::uint8_t _scramble(std::uint8_t x) {
    x ^= static_cast<std::uint8_t>((x << 3U) | (x >> 5U));
    x ^= 0x5AU;
    return x;
}

static std::uint16_t _compute_crc(std::uint8_t _data) { // NC
    std::uint8_t s = _scramble(_data);
    return static_cast<std::uint16_t>(static_cast<std::uint16_t>(s) ^ 0x00FFU);
}

static void _printSeq(const std::vector<std::uint8_t> &_v) {
    for (auto b : _v) {
        std::uint16_t c = _compute_crc(b);
        std::cout << "b=0x" << std::hex << std::setw(2) << std::setfill('0')
                  << static_cast<unsigned>(b)
                  << " crc=0x" << std::setw(4) << c << std::dec << std::endl;
    }
}

} // namespace _crc_rule_021

int main() {
    using namespace _crc_rule_021;
    std::vector<std::uint8_t> data;
    data.push_back(0x00U);
    data.push_back(0xABU);
    data.push_back(0xFFU);
    _printSeq(data);
    return 0;
}
