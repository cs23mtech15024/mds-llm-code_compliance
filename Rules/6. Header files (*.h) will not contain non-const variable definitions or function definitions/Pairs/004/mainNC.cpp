// Context: Network packet parser configuration

// -------- Non-Compliant Program (prog_004_nc.cpp)
// Context: Network packet parser
#include <iostream>
#include <cstdint>
#include <cstddef>
#include "seedNC.h" // seed004_magic_header, seed004_is_valid()

namespace net_nc {

void parse_packets(std::uint8_t bytes[], std::size_t n) { // NC array decay
    for (std::size_t i = 0; i < n; ++i) {
        bool ok = seed004_is_valid(bytes[i]);
        std::cout << "b[" << i << "]=" << (int)bytes[i]
                  << " valid=" << (ok ? "Y" : "N") << "\n";
    }
}

int count_valid(std::uint8_t b[], std::size_t n) { // NC
    int c = 0;
    for (std::size_t i = 0; i < n; ++i)
        if (seed004_is_valid(b[i])) ++c;
    return c;
}

} // namespace net_nc

int main() {
    using namespace net_nc;
    std::uint8_t data[6] = {0xDE,0x11,0xAD,0x20,0xBE,0xEF};
    parse_packets(data, 6);
    std::cout << "valid_count=" << count_valid(data,6) << "\n";
    return 0;
}
