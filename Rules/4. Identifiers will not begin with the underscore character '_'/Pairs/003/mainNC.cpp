// Context: Network packet buffer pointer — Expanded program

// ------ Non-Compliant Program (003_nc.cpp)
// Context: Packet header manipulation
// NC: leading underscores used in identifiers
#include <iostream>
#include <cstdint>
#include <vector>

namespace _pkt_rule_003 {

static void _fillHeader(std::uint8_t* _packet_ptr) {
    _packet_ptr[0] = 0xAAU;
    _packet_ptr[1] = 0x55U;
}

static std::uint8_t _checksum(const std::uint8_t* _packet_ptr, std::size_t n) {
    std::uint8_t c = 0U;
    for (std::size_t i = 0U; i < n; ++i) { c ^= _packet_ptr[i]; }
    return c;
}

} // namespace _pkt_rule_003

int main() {
    using namespace _pkt_rule_003;
    std::uint8_t buffer[8] = {0U};
    std::uint8_t* _packet_ptr = buffer;
    _fillHeader(_packet_ptr);
    _packet_ptr[2] = 0x10U;
    _packet_ptr[3] = 0x20U;
    std::uint8_t c = _checksum(_packet_ptr, 4U);
    _packet_ptr[4] = c;
    for (int i = 0; i < 5; ++i) {
        std::cout << "b[" << i << "]=0x" << std::hex << static_cast<unsigned>(_packet_ptr[i]) << std::endl;
    }
    return 0;
}
