// Context: FPGA logic cell configuration bitstream

// Seed 089 — NC: lowercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint32_t cfg=0xbadcafe; // NC
    std::cout << "fpga_cfg=0x" << std::hex << cfg << "\n";
    return 0;
}