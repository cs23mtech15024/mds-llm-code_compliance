// Context: Network packet buffer pointer — Expanded program

// ------ Compliant Program (003_c.cpp)
// Context: Packet header manipulation
// C: identifiers do not begin with '_'
#include <iostream>
#include <cstdint>
#include <vector>

namespace pkt_rule_003 {

static void fillHeader(std::uint8_t* packet_ptr) {
    packet_ptr[0] = 0xAAU;
    packet_ptr[1] = 0x55U;
}

static std::uint8_t checksum(const std::uint8_t* packet_ptr, std::size_t n) {
    std::uint8_t c = 0U;
    for (std::size_t i = 0U; i < n; ++i) { c ^= packet_ptr[i]; }
    return c;
}

} // namespace pkt_rule_003

int main() {
    using namespace pkt_rule_003;
    std::uint8_t buffer[8] = {0U};
    std::uint8_t* packet_ptr = buffer;
    fillHeader(packet_ptr);
    packet_ptr[2] = 0x10U;
    packet_ptr[3] = 0x20U;
    std::uint8_t c = checksum(packet_ptr, 4U);
    packet_ptr[4] = c;
    for (int i = 0; i < 5; ++i) {
        std::cout << "b[" << i << "]=0x" << std::hex << static_cast<unsigned>(packet_ptr[i]) << std::endl;
    }
    return 0;
}
