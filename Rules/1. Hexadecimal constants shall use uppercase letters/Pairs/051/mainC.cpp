// Context: Forklift ref height literal

// program_051_c.cpp
// Context: Forklift ref height literal
// Rule: MISRA C++ 2-13-4 — Hex digits A–F must be uppercase.
// Violation: Uses lowercase hex digits (a-f)

#include <iostream>
#include <cstdint>
#include <array>

namespace app_051 {

constexpr uint16_t CONFIG_A = 0XABCD;  // NC: lowercase a,b,c,d
constexpr uint16_t CONFIG_B = 0XEF12;  // NC: lowercase e,f
constexpr uint8_t MASK_HIGH = 0XFF;    // NC: lowercase f
constexpr uint8_t MASK_LOW = 0X0F;     // NC: lowercase f

uint32_t combine_configs() {
    uint32_t result = 0X00000000;
    result = static_cast<uint32_t>((CONFIG_A << 16) | CONFIG_B);
    return result;
}

uint8_t extract_byte(uint32_t value, uint8_t index) {
    uint8_t shift = static_cast<uint8_t>(index * 8);
    return static_cast<uint8_t>((value >> shift) & MASK_HIGH);
}

bool check_flags(uint32_t value) {
    uint8_t test = static_cast<uint8_t>(value & MASK_LOW);
    return (test == 0X0A) || (test == 0X0B) || (test == 0X0C);  // NC: lowercase
}

void process_data(const std::array<uint32_t, 4>& data) {
    std::cout << "=== Forklift ref height literal ===\n";
    
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

} // namespace app_051

int main() {
    uint32_t combined = app_051::combine_configs();
    std::cout << "Combined: 0x" << std::hex << combined << std::dec << "\n\n";
    
    std::array<uint32_t, 4> test_data = {
        0XABCDEF12, 0X12345678,  // NC: lowercase hex
        0XFEDCBA98, 0XDEADBEEF   // NC: lowercase hex
    };
    
    app_051::process_data(test_data);
    
    return 0;
}