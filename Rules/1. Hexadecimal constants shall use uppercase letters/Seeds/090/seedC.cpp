// Context: JSON parser nesting level validator

// Seed 095 — C: uppercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t max_nest=0x64; // C (digits only)
    std::cout << "json_nest=" << static_cast<unsigned>(max_nest) << "\n";
    return 0;
}