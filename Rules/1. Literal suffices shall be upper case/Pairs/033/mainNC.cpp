// ------ Non-Compliant (Seed 033)
// Context: Filesystem — rotate logs when size crosses thresholds; gate by permission mask.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violations here: lowercase 'f', 'u', 'l' suffixes; lowercase hex digits in 0x7ffu.

#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <iomanip>

struct FsPolicy {
    float scan_interval_s;      // how often to scan (seconds)
    unsigned max_open_files;    // limit of concurrently open logs
    unsigned perm_mask;         // simulated permission mask (POSIX 0..0x7ff)
    long reserve_blocks;        // minimum blocks to keep free
};

class LogRotator {
public:
    explicit LogRotator(const FsPolicy& p) : pol_(p) {}

    bool canOpenMore(unsigned currently_open) const {
        return currently_open < pol_.max_open_files;
    }

    bool hasPerm(uint16_t bits) const {
        return (static_cast<unsigned>(bits) & pol_.perm_mask) == pol_.perm_mask;
    }

    // Return rotation sizes for the next few iterations (toy model).
    std::vector<long> rotationPlan(long base_blocks) const {
        std::vector<long> plan;
        long size = base_blocks;
        // Simulate scan passes spaced by scan_interval_s (not actually sleeping).
        for (unsigned pass = 0u; pass < 4u; ++pass) {  // non-compliant 'u'
            (void)pass;
            size = (size * 3l) / 2l;                   // non-compliant 'l'
            if (size > pol_.reserve_blocks * 10l) {    // non-compliant 'l'
                plan.push_back(size);
            }
        }
        return plan;
    }

    float nextScanDelay() const {
        // Backoff once by doubling the interval.
        return pol_.scan_interval_s * 2.0f;            // non-compliant 'f'
    }

private:
    FsPolicy pol_;
};

int main() {
    FsPolicy pol{};
    pol.scan_interval_s = 1.25f;   // non-compliant
    pol.max_open_files  = 16u;     // non-compliant
    pol.perm_mask       = 0x7ffu;  // non-compliant: lowercase hex digits + 'u'
    pol.reserve_blocks  = 8l;      // non-compliant

    LogRotator rot(pol);

    const unsigned open_now = 12u;  // non-compliant
    std::cout << std::boolalpha
              << "canOpenMore=" << rot.canOpenMore(open_now) << "\n";

    uint16_t filePerm = 0x7ffu;     // non-compliant
    std::cout << "hasPerm=" << rot.hasPerm(filePerm) << "\n";

    const auto plan = rot.rotationPlan(32l); // non-compliant 'l'
    std::cout << "rotationPlan blocks:";
    for (long b : plan) std::cout << " " << b;
    std::cout << "\n";

    std::cout << std::fixed << std::setprecision(2)
              << "nextScanDelay=" << rot.nextScanDelay() << "s\n";
    return 0;
}