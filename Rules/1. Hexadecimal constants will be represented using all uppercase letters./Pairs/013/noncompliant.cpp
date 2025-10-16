// ------ Non-Compliant
// Pair 13 — Seed: 0xffU -> 0xffu
// Context: Model of mesh packet routing table in DRDO SDR-based Tactical Communication System.
// Violation: lowercase 'u' suffix hindering clarity.
// Note: For this pair the non-compliant literal used is 0xffu (lowercase hex letters + lowercase 'u').
// Source: MISRA C++ Rule 2-13-4 (literal suffixes shall be upper case) and JSF-AV hex guidance.

#include <cstdint>
#include <iostream>
#include <vector>
#include <iomanip>

struct MeshEntry_NC {
    uint32_t id;
    uint32_t routeMask = 0xffu; // NC: lowercase hex + lowercase 'u'
    bool canRoute(uint32_t dest) const {
        return (routeMask & dest) != 0u;
    }
};

int main() {
    // Build a small routing table
    std::vector<MeshEntry_NC> table;
    table.push_back({1u, 0xffu});
    table.push_back({2u, 0x0fu});
    table.push_back({3u, 0xF0u}); // mixed-case to simulate existing inconsistency

    uint32_t probe = 0x0Au; // NC: lowercase suffix on probe literal
    std::cout << "[NC] Probe mask: 0x" << std::hex << probe << std::dec << "\n";

    for (const auto &e : table) {
        bool ok = e.canRoute(probe);
        std::cout << "[NC] Node " << e.id << " routeMask=0x" << std::hex << e.routeMask
                  << std::dec << " canRoute=" << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}