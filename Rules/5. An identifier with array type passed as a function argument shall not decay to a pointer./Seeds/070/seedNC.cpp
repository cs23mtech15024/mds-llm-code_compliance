// Context: DMA transfer descriptor chain

// Seed 070 — NC: DMA descriptors decay to pointer
#include <iostream>
#include <cstdint>
void setup_dma_chain(std::uint32_t descriptors[]) { // NC
    descriptors[0] = 0x20000000;
    std::cout << "dma0=0x" << std::hex << descriptors[0] << "\n";
}
int main(){
    std::uint32_t dma_chain[16] = {0};
    setup_dma_chain(dma_chain);
    return 0;
}