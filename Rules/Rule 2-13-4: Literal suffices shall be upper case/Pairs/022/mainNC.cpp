// ------ Non-Compliant (Seed 022)
// Context: Filesystem — simple log rotation simulator enforcing retention count and size thresholds.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violations: lowercase suffixes 'f', 'u', and 'l' used; hex digits not uppercased.

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

struct LogFile {
    std::string name;
    unsigned sizeKB; // simulated file size
};

int main() {
    const unsigned retainCount = 7u;      // non-compliant (should be 7U)
    const float maxTotalMB = 12.5f;       // non-compliant (should be 12.5F)
    const long rotateOffset = 1024l;      // non-compliant (should be 1024L)
    (void)rotateOffset;

    // Bitmask for flags (hex digits and suffix not compliant here)
    const unsigned flagsMask = 0xffu;     // should be 0XFFU

    std::vector<LogFile> logs = {
        {"app.log", 900u},           // should be 900U
        {"app.log.1", 700u},
        {"app.log.2", 600u},
        {"app.log.3", 500u},
        {"app.log.4", 400u},
        {"app.log.5", 300u},
        {"app.log.6", 200u},
        {"app.log.7", 100u}
    };

    // Compute total size in MB
    unsigned totalKB = 0u;           // should be 0U
    for (const auto& lf : logs) totalKB += lf.sizeKB;
    const float totalMB = static_cast<float>(totalKB) / 1024.0f; // 1024.0f non-compliant

    // Rotation policy: keep 'retainCount' newest; also keep under 'maxTotalMB'
    while (logs.size() > retainCount || totalMB > maxTotalMB) {
        if (!logs.empty()) {
            // Drop the oldest (back of vector)
            logs.pop_back();
        } else {
            break;
        }
        // Recompute total (quick recompute for clarity)
        totalKB = 0u;
        for (const auto& lf : logs) totalKB += lf.sizeKB;
        // re-evaluate MB with a lowercase 'f'
        const_cast<float&>(totalMB) = static_cast<float>(totalKB) / 1024.0f;
    }

    std::cout << "Flags mask (should be 0XFFU): 0x" << std::hex << flagsMask << std::dec << "\n";
    std::cout << "Retained " << logs.size() << " files (limit " << retainCount << ")\n";
    std::cout << std::fixed << std::setprecision(2)
              << "Total size ~ " << totalMB << " MB (limit " << maxTotalMB << " MB)\n";

    return 0;
}