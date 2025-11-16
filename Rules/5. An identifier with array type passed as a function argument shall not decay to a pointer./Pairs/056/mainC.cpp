// Context: Bluetooth device MAC addresses

// ------ Compliant Program (056_c.cpp)
// Context: Bluetooth MAC address (6 bytes)
// Rule: Preserve array extent (COMPLIANT)
// C: store_mac_address takes reference to array[6]
#include <iostream>
#include <cstdint>
#include <iomanip>

namespace mac_056_c {

void store_mac_address(std::uint8_t (&mac)[6]) { // C API exact bound
    mac[0] = 0xAAU;
    std::cout << "mac0=0x" << std::hex << std::uppercase
              << static_cast<int>(mac[0]) << "\n";
}

} // namespace mac_056_c

int main() {
    using namespace mac_056_c;
    std::uint8_t bt_mac[6] = {0};
    store_mac_address(bt_mac);
    return 0;
}
