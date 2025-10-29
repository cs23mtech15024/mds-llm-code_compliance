// Context: Operating system process priority level

// Seed 085 — C: uppercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t prio=0x7F; // C
    std::cout << "prio=0x" << std::hex << static_cast<unsigned>(prio) << "\n";
    return 0;
}