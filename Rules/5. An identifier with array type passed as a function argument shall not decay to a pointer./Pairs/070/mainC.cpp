// Context: DMA transfer descriptor chain

// ------ Compliant Program (070_c.cpp)
// Context: Initialize first DMA descriptor word
// Rule: Preserve array via reference (COMPLIANT)
#include <iostream>
#include <cstdint>
#include <cstddef>
#include <iomanip>

namespace dma_070_c {

constexpr std::size_t kDesc = 16U;

template <std::size_t N>
static void write_word(std::uint32_t (&d)[N], std::size_t i, std::uint32_t v) {
    static_assert(N == 16U, "expect 16 descriptors");
    if (i < N) d[i] = v;
}

template <std::size_t N>
static std::uint32_t read_word(const std::uint32_t (&d)[N], std::size_t i) {
    return (i < N) ? d[i] : 0U;
}

void setup_dma_chain(std::uint32_t (&descriptors)[kDesc]) { // C API
    write_word(descriptors, 0U, 0x20000000U);
    std::cout << "dma0=0x" << std::hex << std::uppercase
              << read_word(descriptors, 0U) << "\n";
}

} // namespace dma_070_c

int main() {
    using namespace dma_070_c;
    std::uint32_t chain[kDesc] = {0};
    setup_dma_chain(chain);
    return 0;
}
