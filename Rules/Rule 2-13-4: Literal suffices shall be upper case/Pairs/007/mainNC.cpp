// Context: Build a 64-bit telemetry packet ID from subsystem, channel, and sequence fields.
// Rule violated: MISRA C++ 2-13-4 — Literal suffixes shall be upper case.
// Seed: Non-compliant: const unsigned long long base = 1ull;   // Compliant: const unsigned long long base = 1ULL;
// Violation: Lowercase ‘ull’ used for unsigned long long literals.

#include <iostream>
#include <cstdint>
#include <iomanip>

struct PacketFields {
    std::uint16_t subsystem; // 10 bits
    std::uint16_t channel;   // 10 bits
    std::uint32_t sequence;  // 20 bits
};

unsigned long long buildPacketId(const PacketFields& f)
{
    // Layout: [ subsystem:10 | channel:10 | sequence:20 | reserved:24 ]
    const unsigned long long SUBSYS_SHIFT = 54ull;  // NC
    const unsigned long long CHAN_SHIFT   = 44ull;  // NC
    const unsigned long long SEQ_SHIFT    = 24ull;  // NC

    const unsigned long long SUBSYS_MASK  = (1ull << 10ull) - 1ull; // NC
    const unsigned long long CHAN_MASK    = (1ull << 10ull) - 1ull; // NC
    const unsigned long long SEQ_MASK     = (1ull << 20ull) - 1ull; // NC

    unsigned long long sid = (static_cast<unsigned long long>(f.subsystem) & SUBSYS_MASK) << SUBSYS_SHIFT;
    unsigned long long cid = (static_cast<unsigned long long>(f.channel)   & CHAN_MASK)   << CHAN_SHIFT;
    unsigned long long sq  = (static_cast<unsigned long long>(f.sequence)  & SEQ_MASK)    << SEQ_SHIFT;

    return sid | cid | sq;
}

int main()
{
    PacketFields f{ 17, 512 % 1024, 104857 % 1048576 }; // bounded
    unsigned long long id = buildPacketId(f);

    std::cout << "PacketID: 0x" << std::hex << std::uppercase
              << id << std::dec << "\n";

    // Extract back to verify determinism:
    const unsigned long long SUBSYS_SHIFT = 54ull; // NC
    const unsigned long long CHAN_SHIFT   = 44ull; // NC
    const unsigned long long SEQ_SHIFT    = 24ull; // NC
    const unsigned long long SUBSYS_MASK  = (1ull << 10ull) - 1ull; // NC
    const unsigned long long CHAN_MASK    = (1ull << 10ull) - 1ull; // NC
    const unsigned long long SEQ_MASK     = (1ull << 20ull) - 1ull; // NC

    std::uint16_t subsystem = static_cast<std::uint16_t>((id >> SUBSYS_SHIFT) & SUBSYS_MASK);
    std::uint16_t channel   = static_cast<std::uint16_t>((id >> CHAN_SHIFT)   & CHAN_MASK);
    std::uint32_t sequence  = static_cast<std::uint32_t>((id >> SEQ_SHIFT)    & SEQ_MASK);

    std::cout << "Decoded: subsystem=" << subsystem
              << " channel=" << channel
              << " sequence=" << sequence << "\n";
    return 0;
}