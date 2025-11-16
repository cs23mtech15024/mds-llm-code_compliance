// Context: Bluetooth device pairing table header

// -------- Compliant Program (prog_014_c.cpp)
// Context: Bluetooth pairing table — COMPLIANT
#include <iostream>
#include <cstdint>
#include <cstddef>
#include "seedC.h" // extern seed014_paired[], seed014_is_paired()

// Definitions
std::uint64_t seed014_paired[4] = {0};
bool seed014_is_paired(std::uint64_t id) { return seed014_paired[0] == id; }

namespace bt_c {

void add_pair(std::uint64_t id) {
    seed014_paired[0] = id; // defined in this TU
}

template <std::size_t N>
void test(const std::uint64_t (&ids)[N]) {
    for (std::size_t i = 0; i < N; ++i) {
        add_pair(ids[i]);
        std::cout << "is_paired(" << ids[i] << ")=" << seed014_is_paired(ids[i]) << "\n";
        std::cout << "paired:";
        for (int j = 0; j < 4; ++j) std::cout << ' ' << seed014_paired[j];
        std::cout << "\n";
    }
}

} // namespace bt_c

int main() {
    using namespace bt_c;
    const std::uint64_t ids[2] = {0xAABBCCDDEEFFULL, 0x112233445566ULL};
    test(ids);
    return 0;
}
