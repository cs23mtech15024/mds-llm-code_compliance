// Context: Network packet checksum calculator

// ------ Compliant Program (003_c.cpp)
// Context: Network packet checksum calculator
// C: data accepted by reference to array; helpers use array refs
#include <iostream>
#include <cstdint>
#include <cstddef>

namespace pkt_003_c {

template <std::size_t N>
static std::uint16_t partial(const std::uint8_t (&data)[N]) { // C
    std::uint32_t acc = 0U;
    for (std::size_t i = 0; i < N; ++i) { acc += data[i]; }
    return static_cast<std::uint16_t>(acc & 0xFFFFU);
}

template <std::size_t N>
std::uint16_t calc_checksum(std::uint8_t (&data)[N]) { // C
    return static_cast<std::uint16_t>(partial(data) + data[0] + data[1]);
}

} // namespace pkt_003_c

int main() {
    using namespace pkt_003_c;
    std::uint8_t packet[64] = {0xAAU, 0xBBU};
    std::cout << "checksum=" << calc_checksum(packet) << "\n";
    return 0;
}
