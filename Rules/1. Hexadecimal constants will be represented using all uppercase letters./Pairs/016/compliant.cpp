// ------ Compliant
// Pair 16 — Seed: 128ul -> 128UL
// Context: Access control mask in Maya OS security module.
// Violation: lowercase 'ul' suffix inconsistent within kernel code.
// Source: MISRA C++ Rule 2-13-4 (literal suffixes shall be upper case).

#include <cstdint>
#include <iostream>
#include <vector>
#include <string>

class SecurityModule_C {
public:
    // Compliant mask using uppercase 'UL' suffix (seed corrected)
    static constexpr uint32_t DEFAULT_ACCESS_MASK = 0x00FFUL; // C: hex + uppercase 'UL'
    static constexpr unsigned long MAX_ENTRIES = 128UL;       // C: uppercase 'UL'

    struct Entry {
        uint32_t id;
        uint32_t accessMask;
        std::string name;
    };

    SecurityModule_C() {
        // initialize some mock entries (compliant suffixes)
        entries.push_back({1U, DEFAULT_ACCESS_MASK, "root"});     // C: 1U
        entries.push_back({2U, 0x0001UL, "service"});            // C
        entries.push_back({3U, 0x0002UL, "user"});               // C
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
        std::cout << "[C] MAX_ENTRIES = " << MAX_ENTRIES << "\n";
        uint32_t probeMask = 0x0001UL; // C
        std::cout << "[C] Probe mask = 0x" << std::hex << probeMask << std::dec << "\n";
        for (const auto &e : entries) {
            std::cout << "[C] Entry " << e.id << " (" << e.name << ") accessMask=0x"
                      << std::hex << e.accessMask << std::dec
                      << " hasProbe=" << (hasAccess(e.id, probeMask) ? "YES" : "NO") << "\n";
        }
    }

private:
    std::vector<Entry> entries;
};

int main() {
    SecurityModule_C sm;
    sm.demo();
    return 0;
}