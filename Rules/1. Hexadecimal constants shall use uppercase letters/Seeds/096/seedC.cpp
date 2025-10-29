// Context: BitTorrent piece hash verification index

// Seed 098 — C: uppercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t piece=0x3FF; // C
    std::cout << "bt_piece=0x" << std::hex << piece << "\n";
    return 0;
}