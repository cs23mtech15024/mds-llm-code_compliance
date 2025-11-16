// Context: Encryption key rotation buffer

// ------ Compliant Program (007_c.cpp)
// Context: Encryption key rotation buffer
// C: keys accepted by reference; helper uses array ref
#include <iostream>
#include <cstdint>
#include <cstddef>
#include <iomanip>

namespace key_007_c {

template <std::size_t N>
static void xor_first(std::uint8_t (&keys)[N], std::uint8_t mask) { // C
    if (N > 0U) { keys[0] ^= mask; }
}

template <std::size_t N>
void rotate_keys(std::uint8_t (&keys)[N]) { // C
    xor_first(keys, 0xFFU);
    std::cout << "key0=0x" << std::hex << static_cast<int>(keys[0]) << "\n";
}

} // namespace key_007_c

int main() {
    using namespace key_007_c;
    std::uint8_t key_buffer[32] = {0xABU};
    rotate_keys(key_buffer);
    return 0;
}
