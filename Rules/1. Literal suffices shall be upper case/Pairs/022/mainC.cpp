// ------ Compliant (Seed 022)
// Context: Filesystem — simple log rotation simulator enforcing retention count and size thresholds.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Fixes: all suffixes changed to uppercase F, U, and L; hex digits uppercased.

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

struct LogFile {
    std::string name;
    unsigned sizeKB;
};

int main() {
    const unsigned retainCount = 7U;       // compliant
    const float maxTotalMB = 12.5F;        // compliant
    const long rotateOffset = 1024L;       // compliant
    (void)rotateOffset;

    const unsigned flagsMask = 0XFFU;      // compliant (hex + suffix uppercase)

    std::vector<LogFile> logs = {
        {"app.log", 900U},
        {"app.log.1", 700U},
        {"app.log.2", 600U},
        {"app.log.3", 500U},
        {"app.log.4", 400U},
        {"app.log.5", 300U},
        {"app.log.6", 200U},
        {"app.log.7", 100U}
    };

    unsigned totalKB = 0U;                 // compliant
    for (const auto& lf : logs) totalKB += lf.sizeKB;
    float totalMB = static_cast<float>(totalKB) / 1024.0F; // compliant

    while (logs.size() > retainCount || totalMB > maxTotalMB) {
        if (!logs.empty()) {
            logs.pop_back();
        } else {
            break;
        }
        totalKB = 0U;
        for (const auto& lf : logs) totalKB += lf.sizeKB;
        totalMB = static_cast<float>(totalKB) / 1024.0F;   // compliant
    }

    std::cout << "Flags mask (0XFFU): 0x" << std::hex << flagsMask << std::dec << "\n";
    std::cout << "Retained " << logs.size() << " files (limit " << retainCount << ")\n";
    std::cout << std::fixed << std::setprecision(2)
              << "Total size ~ " << totalMB << " MB (limit " << maxTotalMB << " MB)\n";

    return 0;
}