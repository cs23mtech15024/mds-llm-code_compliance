// Context: PDF page object reference number

// Seed 093 — C: uppercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint32_t obj=0x1A2B; // C
    std::cout << "pdf_obj=0x" << std::hex << obj << "\n";
    return 0;
}