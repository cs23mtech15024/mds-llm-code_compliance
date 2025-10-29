// Context: WebAssembly linear memory page count

// Seed 099 — NC: lowercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t pages=0x100; // NC: 256 pages
    std::cout << "wasm_pages=0x" << std::hex << pages << "\n";
    return 0;
}