// Context: DMA transfer descriptor chain

// ------ Non-Compliant Program (070_nc.cpp)
// Context: Initialize first DMA descriptor word
// Rule: Array parameter decays to pointer (VIOLATED)
#include <iostream>
#include <cstdint>
#include <cstddef>
#include <iomanip>

namespace dma_070_nc {

constexpr std::size_t kDesc = 16U;

static void write_word(std::uint32_t *d, std::size_t n, std::size_t i, std::uint32_t v) { // NC
    if (i < n) d[i] = v;
}

static std::uint32_t read_word(const std::uint32_t *d, std::size_t n, std::size_t i) { // NC
    return (i < n) ? d[i] : 0U;
}

void setup_dma_chain(std::uint32_t descriptors[]) { // NC API
    write_word(descriptors, kDesc, 0U, 0x20000000U);
    std::cout << "dma0=0x" << std::hex << std::uppercase
              << read_word(descriptors, kDesc, 0U) << "\n";
}

} // namespace dma_070_nc

int main() {
    using namespace dma_070_nc;
    std::uint32_t chain[kDesc] = {0};
    setup_dma_chain(chain);
    return 0;
}
