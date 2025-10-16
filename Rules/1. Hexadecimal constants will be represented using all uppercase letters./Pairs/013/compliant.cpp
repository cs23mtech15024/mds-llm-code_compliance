// ------ Compliant
// Pair 13 — Seed: 0xffU -> 0xffu
// Context: Model of mesh packet routing table in DRDO SDR-based Tactical Communication System.
// Violation: lowercase 'u' suffix hindering clarity.
// Note: For this pair the compliant literal used is 0xFFU (uppercase hex letters + uppercase 'U').
// Source: MISRA C++ Rule 2-13-4 (literal suffixes shall be upper case) and JSF-AV hex guidance.

#include <cstdint>
#include <iostream>
#include <vector>
#include <iomanip>

struct MeshEntry_C {
    uint32_t id;
    uint32_t routeMask = 0xFFU; // C: uppercase hex + uppercase 'U'
    bool canRoute(uint32_t dest) const {
        return (routeMask & dest) != 0U;
    }
};

int main() {
    // Build a small routing table (compliant literals)
    std::vector<MeshEntry_C> table;
    table.push_back({1U, 0xFFU});
    table.push_back({2U, 0x0FU});
    table.push_back({3U, 0xF0U});

    uint32_t probe = 0x0AU; // C: uppercase hex and 'U'
    std::cout << "[C] Probe mask: 0x" << std::hex << probe << std::dec << "\n";

    for (const auto &e : table) {
        bool ok = e.canRoute(probe);
        std::cout << "[C] Node " << e.id << " routeMask=0x" << std::hex << e.routeMask
                  << std::dec << " canRoute=" << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}