// Context: Networking – buffer sizing and feature flags using numeric literals.
// Rule satisfied: MISRA C++ 2-13-4 — Literal suffixes shall be upper case.
// Seed: Non-compliant: const unsigned recv_buf = 4096u;   // Compliant: const unsigned recv_buf = 4096U

#include <iostream>
#include <cstdint>
#include <vector>
#include <numeric>
#include <iomanip>

namespace netcfg {
    // Feature flags (compliant: upper-case suffixes/prefix)
    constexpr std::uint32_t F_NAGLE_OFF  = 0X01U;
    constexpr std::uint32_t F_QUICK_ACK  = 0X02U;
    constexpr std::uint32_t F_REUSE_ADDR = 0X10U;

    // Buffer defaults (compliant suffixes)
    constexpr unsigned RECV_BUF = 4096U;
    constexpr unsigned SEND_BUF = 65535UL;   // 'UL' compliant
    constexpr std::uint64_t MAX_BYTES = 1ULL << 20; // 1 MiB (compliant 'ULL')

    // Compute an effective window size based on flags (toy logic)
    constexpr unsigned window(unsigned base, std::uint32_t flags) {
        unsigned w = base;
        if ((flags & F_QUICK_ACK) != 0U)  w += 512U;
        if ((flags & F_NAGLE_OFF) != 0U)  w += 256U;
        return w;
    }
}

int main() {
    using namespace netcfg;

    std::uint32_t flags = F_NAGLE_OFF | F_QUICK_ACK;
    unsigned recv = RECV_BUF;
    unsigned send = SEND_BUF;

    unsigned win  = window(recv, flags);
    std::vector<unsigned> chunks;
    unsigned mtu = 1460U; // compliant 'U'
    for (unsigned off = 0U; off < win; off += mtu) {
        unsigned remaining = (win - off);
        unsigned sz = remaining < mtu ? remaining : mtu;
        chunks.push_back(sz);
    }

    std::uint64_t total = std::accumulate(chunks.begin(), chunks.end(), 0ULL); // compliant 'ULL'

    std::cout << "Flags=0x" << std::hex << flags
              << " recv=" << std::dec << recv
              << " send=" << send
              << " win="  << win
              << " mtu="  << mtu
              << " chunks=" << chunks.size()
              << " total=" << total << "\n";

    return 0;
}