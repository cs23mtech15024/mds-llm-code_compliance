// Context: Controller integral cap register

// Seed 015 — NC: lowercase hex cap
#include <cstdint>
#include <iostream>
int main(){
    std::uint32_t cap=0x3e8; // NC: 1000
    std::cout << "icap=" << cap << "\n";
    return 0;
}