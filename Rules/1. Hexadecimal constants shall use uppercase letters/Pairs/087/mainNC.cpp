// Context: Smart home Z-Wave device node identifier

// program_087_nc.cpp
// Context: Smart home Z-Wave device node identifier
// Rule: MISRA C++ 2-13-4 — Hex digits A–F must be uppercase.
// Violation: Uses lowercase hex digits (a-f)

#include <iostream>
#include <cstdint>
#include <array>

namespace app_087 {

constexpr uint16_t CONFIG_A = 0xabcd;  // NC: lowercase a,b,c,d
constexpr uint16_t CONFIG_B = 0xef12;  // NC: lowercase e,f
constexpr uint8_t MASK_HIGH = 0xff;    // NC: lowercase f
constexpr uint8_t MASK_LOW = 0x0f;     // NC: lowercase f

uint32_t combine_configs() {
    uint32_t result = 0x00000000;
    result = static_cast<uint32_t>((CONFIG_A << 16) | CONFIG_B);
    return result;
}

uint8_t extract_byte(uint32_t value, uint8_t index) {
    uint8_t shift = static_cast<uint8_t>(index * 8);
    return static_cast<uint8_t>((value >> shift) & MASK_HIGH);
}

bool check_flags(uint32_t value) {
    uint8_t test = static_cast<uint8_t>(value & MASK_LOW);
    return (test == 0x0a) || (test == 0x0b) || (test == 0x0c);  // NC: lowercase
}

void process_data(const std::array<uint32_t, 4>& data) {
    std::cout << "=== Smart home Z-Wave device node identifier ===\n";
    
    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << "Data[" << i << "]: 0x" << std::hex << data[i] << std::dec;
        
        if (check_flags(data[i])) {
            std::cout << " [FLAGGED]";
        }
        
        std::cout << "\n";
        
        for (uint8_t j = 0; j < 4; ++j) {
            uint8_t byte = extract_byte(data[i], j);
            std::cout << "  Byte " << static_cast<unsigned>(j)
                      << ": 0x" << std::hex << static_cast<unsigned>(byte)
                      << std::dec << "\n";
        }
    }
}

} // namespace app_087

int main() {
    uint32_t combined = app_087::combine_configs();
    std::cout << "Combined: 0x" << std::hex << combined << std::dec << "\n\n";
    
    std::array<uint32_t, 4> test_data = {
        0xabcdef12, 0x12345678,  // NC: lowercase hex
        0xfedcba98, 0xdeadbeef   // NC: lowercase hex
    };
    
    app_087::process_data(test_data);
    
    return 0;
}