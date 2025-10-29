// Context: ZIP archive compression method identifier

// Seed 092 — C: uppercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t method=0x08; // C (digits only)
    std::cout << "zip_method=0x" << std::hex << method << "\n";
    return 0;
}