// Context: ZIP archive compression method identifier

// Seed 092 — NC: lowercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t method=0x08; // NC: deflate
    std::cout << "zip_method=0x" << std::hex << method << "\n";
    return 0;
}