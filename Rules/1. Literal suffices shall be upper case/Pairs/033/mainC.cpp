// ------ Compliant (Seed 033)
// Context: Filesystem — rotate logs when size crosses thresholds; gate by permission mask.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Fixes: all literal suffixes changed to uppercase ('F','U','L'), and hex digits to uppercase (0X7FFU).

#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <iomanip>

struct FsPolicy {
    float scan_interval_s;      // how often to scan (seconds)
    unsigned max_open_files;    // limit of concurrently open logs
    unsigned perm_mask;         // simulated permission mask (POSIX 0..0X7FF)
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

    std::vector<long> rotationPlan(long base_blocks) const {
        std::vector<long> plan;
        long size = base_blocks;
        for (unsigned pass = 0U; pass < 4U; ++pass) {  // compliant 'U'
            (void)pass;
            size = (size * 3L) / 2L;                   // compliant 'L'
            if (size > pol_.reserve_blocks * 10L) {    // compliant 'L'
                plan.push_back(size);
            }
        }
        return plan;
    }

    float nextScanDelay() const {
        return pol_.scan_interval_s * 2.0F;            // compliant 'F'
    }

private:
    FsPolicy pol_;
};

int main() {
    FsPolicy pol{};
    pol.scan_interval_s = 1.25F;   // compliant
    pol.max_open_files  = 16U;     // compliant
    pol.perm_mask       = 0X7FFU;  // compliant: uppercase hex + 'U'
    pol.reserve_blocks  = 8L;      // compliant

    LogRotator rot(pol);

    const unsigned open_now = 12U;  // compliant
    std::cout << std::boolalpha
              << "canOpenMore=" << rot.canOpenMore(open_now) << "\n";

    uint16_t filePerm = 0X7FFU;     // compliant
    std::cout << "hasPerm=" << rot.hasPerm(filePerm) << "\n";

    const auto plan = rot.rotationPlan(32L); // compliant 'L'
    std::cout << "rotationPlan blocks:";
    for (long b : plan) std::cout << " " << b;
    std::cout << "\n";

    std::cout << std::fixed << std::setprecision(2)
              << "nextScanDelay=" << rot.nextScanDelay() << "s\n";
    return 0;
}