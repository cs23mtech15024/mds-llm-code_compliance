// Context: EEPROM memory page buffer

// ------ Non-Compliant Program (021_nc.cpp)
// Context: Write a byte into a 128-byte EEPROM page buffer
// Rule: An identifier with array type passed as a function argument shall not decay to a pointer.
// Status: VIOLATED (array parameter decays to pointer)
#include <iostream>
#include <cstdint>
#include <iomanip>

namespace eeprom_021_nc {

static void stamp(std::uint8_t *page, std::size_t idx, std::uint8_t val) { // NC helper
    page[idx] = val;
}

void write_page(std::uint8_t page_data[]) { // NC API
    const std::size_t N = 128U;
    (void)N; // page has fixed size but not enforced here
    stamp(page_data, 0U, 0xDE);
    std::cout << "byte0=0x" << std::hex << std::uppercase
              << static_cast<int>(page_data[0]) << "\n";
}

} // namespace eeprom_021_nc

int main() {
    using namespace eeprom_021_nc;
    std::uint8_t eeprom_page[128] = {0};
    write_page(eeprom_page);
    return 0;
}
