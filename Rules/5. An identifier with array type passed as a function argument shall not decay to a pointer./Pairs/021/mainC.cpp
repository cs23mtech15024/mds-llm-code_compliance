// Context: EEPROM memory page buffer

// ------ Compliant Program (021_c.cpp)
// Context: Write a byte into a 128-byte EEPROM page buffer
// Status: COMPLIANT (array passed by reference)
#include <iostream>
#include <cstdint>
#include <iomanip>

namespace eeprom_021_c {

static void stamp(std::uint8_t (&page)[128], std::size_t idx, std::uint8_t val) { // C helper
    page[idx] = val;
}

void write_page(std::uint8_t (&page_data)[128]) { // C API
    stamp(page_data, 0U, 0xDE);
    std::cout << "byte0=0x" << std::hex << std::uppercase
              << static_cast<int>(page_data[0]) << "\n";
}

} // namespace eeprom_021_c

int main() {
    using namespace eeprom_021_c;
    std::uint8_t eeprom_page[128] = {0};
    write_page(eeprom_page);
    return 0;
}
