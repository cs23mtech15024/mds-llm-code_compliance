// Context: Operating system process priority level

// Seed 085 — NC: lowercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t prio=0x7f; // NC: highest priority
    std::cout << "prio=0x" << std::hex << static_cast<unsigned>(prio) << "\n";
    return 0;
}