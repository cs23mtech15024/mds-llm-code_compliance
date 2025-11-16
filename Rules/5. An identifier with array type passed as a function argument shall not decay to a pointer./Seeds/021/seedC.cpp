// Context: EEPROM memory page buffer

// Seed 021 — C: EEPROM buffer by reference
#include <iostream>
#include <cstdint>
void write_page(std::uint8_t (&page_data)[128]) { // C
    page_data[0] = 0xDE;
    std::cout << "byte0=0x" << std::hex << static_cast<int>(page_data[0]) << "\n";
}
int main(){
    std::uint8_t eeprom_page[128] = {0};
    write_page(eeprom_page);
    return 0;
}