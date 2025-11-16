// Context: Bluetooth device MAC addresses

// ------ Non-Compliant Program (056_nc.cpp)
// Context: Bluetooth MAC address (6 bytes)
// Rule: Array decays to pointer (VIOLATED)
// NC: store_mac_address uses pointer
#include <iostream>
#include <cstdint>
#include <iomanip>

namespace mac_056_nc {

void store_mac_address(std::uint8_t mac[]) { // NC API
    mac[0] = 0xAAU;
    std::cout << "mac0=0x" << std::hex << std::uppercase
              << static_cast<int>(mac[0]) << "\n";
}

} // namespace mac_056_nc

int main() {
    using namespace mac_056_nc;
    std::uint8_t bt_mac[6] = {0};
    store_mac_address(bt_mac);
    return 0;
}
