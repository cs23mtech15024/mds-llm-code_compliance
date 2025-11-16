// Context: Bluetooth device pairing table header

// -------- Non-Compliant Program (prog_014_nc.cpp)
// Context: Bluetooth pairing table
#include <iostream>
#include <cstdint>
#include "seedNC.h" // seed014_paired[], seed014_is_paired()

namespace bt_nc {

void add_pair(std::uint64_t id) {
    seed014_paired[0] = id; // writes into header-defined array (NC)
}

void show_table() {
    std::cout << "paired:";
    for (int i = 0; i < 4; ++i) std::cout << ' ' << seed014_paired[i];
    std::cout << "\n";
}

void test(std::uint64_t ids[], std::size_t n) { // NC decay
    for (std::size_t i = 0; i < n; ++i) {
        add_pair(ids[i]);
        std::cout << "is_paired(" << ids[i] << ")=" << seed014_is_paired(ids[i]) << "\n";
        show_table();
    }
}

} // namespace bt_nc

int main() {
    using namespace bt_nc;
    std::uint64_t ids[2] = {0xAABBCCDDEEFFULL, 0x112233445566ULL};
    test(ids,2);
    return 0;
}
