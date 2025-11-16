// Context: Encryption key rotation buffer

// ------ Non-Compliant Program (007_nc.cpp)
// Context: Encryption key rotation buffer
// NC: keys[] decays; helper uses pointer/length
#include <iostream>
#include <cstdint>
#include <cstddef>
#include <iomanip>

namespace key_007_nc {

static void xor_first(std::uint8_t *keys, std::size_t n, std::uint8_t mask) { // NC
    if (n > 0U) { keys[0] ^= mask; }
}

void rotate_keys(std::uint8_t keys[]) { // NC
    const std::size_t N = 32U;
    xor_first(keys, N, 0xFFU);
    std::cout << "key0=0x" << std::hex << static_cast<int>(keys[0]) << "\n";
}

} // namespace key_007_nc

int main() {
    using namespace key_007_nc;
    std::uint8_t key_buffer[32] = {0xABU};
    rotate_keys(key_buffer);
    return 0;
}
