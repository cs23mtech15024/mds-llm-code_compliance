// Context: Network packet parser configuration

// -------- Compliant Program (prog_004_c.cpp)
// Context: Network packet parser — COMPLIANT
#include <iostream>
#include <cstdint>
#include <cstddef>
#include "seedC.h"

// Definitions
std::uint8_t seed004_magic_header[4] = {0xDE,0xAD,0xBE,0xEF};
bool seed004_is_valid(std::uint8_t b) { return b == seed004_magic_header[0]; }

namespace net_c {

template <std::size_t N>
void parse_packets(const std::uint8_t (&bytes)[N]) {
    for (std::size_t i = 0; i < N; ++i) {
        bool ok = seed004_is_valid(bytes[i]);
        std::cout << "b[" << i << "]=" << (int)bytes[i]
                  << " valid=" << (ok ? "Y" : "N") << "\n";
    }
}

template <std::size_t N>
int count_valid(const std::uint8_t (&bytes)[N]) {
    int c = 0;
    for (auto b : bytes)
        if (seed004_is_valid(b)) ++c;
    return c;
}

} // namespace net_c

int main() {
    using namespace net_c;
    const std::uint8_t data[6] = {0xDE,0x11,0xAD,0x20,0xBE,0xEF};
    parse_packets(data);
    std::cout << "valid_count=" << count_valid(data) << "\n";
    return 0;
}
