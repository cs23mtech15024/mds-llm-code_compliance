// ------ Non-Compliant
// Pair 16 — Seed: 128ul -> 128UL
// Context: Access control mask in Maya OS security module.
// Violation: lowercase 'ul' suffix inconsistent within kernel code.
// Source: MISRA C++ Rule 2-13-4 (literal suffixes shall be upper case).

#include <cstdint>
#include <iostream>
#include <vector>
#include <string>

class SecurityModule_NC {
public:
    // Non-compliant mask using lowercase 'ul' suffix (seed)
    static constexpr uint32_t DEFAULT_ACCESS_MASK = 0x00FFul; // NC: hex + lowercase 'ul'
    static constexpr unsigned long MAX_ENTRIES = 128ul;       // NC: lowercase 'ul'

    struct Entry {
        uint32_t id;
        uint32_t accessMask;
        std::string name;
    };

    SecurityModule_NC() {
        // initialize some mock entries
        entries.push_back({1u, DEFAULT_ACCESS_MASK, "root"});     // NC: 1u
        entries.push_back({2u, 0x0001ul, "service"});            // NC
        entries.push_back({3u, 0x0002ul, "user"});               // NC
    }

    bool hasAccess(uint32_t entryId, uint32_t requiredMask) const {
        for (const auto &e : entries) {
            if (e.id == entryId) {
                return (e.accessMask & requiredMask) == requiredMask;
            }
        }
        return false;
    }

    void demo() const {
        std::cout << "[NC] MAX_ENTRIES = " << MAX_ENTRIES << "\n";
        uint32_t probeMask = 0x0001ul; // NC
        std::cout << "[NC] Probe mask = 0x" << std::hex << probeMask << std::dec << "\n";
        for (const auto &e : entries) {
            std::cout << "[NC] Entry " << e.id << " (" << e.name << ") accessMask=0x"
                      << std::hex << e.accessMask << std::dec
                      << " hasProbe=" << (hasAccess(e.id, probeMask) ? "YES" : "NO") << "\n";
        }
    }

private:
    std::vector<Entry> entries;
};

int main() {
    SecurityModule_NC sm;
    sm.demo();
    return 0;
}