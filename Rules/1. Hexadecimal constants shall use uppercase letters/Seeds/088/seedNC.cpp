// Context: PDF page object reference number

// Seed 093 — NC: lowercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint32_t obj=0x1a2b; // NC
    std::cout << "pdf_obj=0x" << std::hex << obj << "\n";
    return 0;
}