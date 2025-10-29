// Context: BitTorrent piece hash verification index

// Seed 098 — NC: lowercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t piece=0x3ff; // NC: piece 1023
    std::cout << "bt_piece=0x" << std::hex << piece << "\n";
    return 0;
}