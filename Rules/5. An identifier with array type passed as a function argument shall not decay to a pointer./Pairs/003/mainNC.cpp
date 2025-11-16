// Context: Network packet checksum calculator

// ------ Non-Compliant Program (003_nc.cpp)
// Context: Network packet checksum calculator
// NC: data[] decays to pointer; helpers use pointer/length
#include <iostream>
#include <cstdint>
#include <cstddef>

namespace pkt_003_nc {

static std::uint16_t partial(const std::uint8_t *data, std::size_t n) { // NC
    std::uint32_t acc = 0U;
    for (std::size_t i = 0; i < n; ++i) { acc += data[i]; }
    return static_cast<std::uint16_t>(acc & 0xFFFFU);
}

std::uint16_t calc_checksum(std::uint8_t data[]) { // NC
    const std::size_t N = 64U;
    return static_cast<std::uint16_t>(partial(data, N) + data[0] + data[1]);
}

} // namespace pkt_003_nc

int main() {
    using namespace pkt_003_nc;
    std::uint8_t packet[64] = {0xAAU, 0xBBU};
    std::cout << "checksum=" << calc_checksum(packet) << "\n";
    return 0;
}
