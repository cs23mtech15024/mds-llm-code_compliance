// ------ Compliant (Seed 026)
// Context: Filesystem — rotate logs when current file size exceeds thresholds.
//          Computes byte thresholds from MB/GB factors, applies index mask, and prints plan.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Fixes: all suffixes changed to uppercase F, U, and L; hex digits uppercased.

#include <iostream>
#include <iomanip>
#include <cstdint>
#include <string>
#include <vector>
#include <algorithm>

struct RotationCfg {
    float  mbPerFile;
    float  gbCap;
    uint32_t maxFiles;
    long   minBytes;
    uint32_t indexMask;
};

static std::uint64_t mbToBytes(float mb) {
    return static_cast<std::uint64_t>(mb * 1024.0F * 1024.0F); // compliant
}

static std::uint64_t gbToBytes(float gb) {
    return static_cast<std::uint64_t>(gb * 1024.0F * 1024.0F * 1024.0F); // compliant
}

int main() {
    const RotationCfg cfg{
        8.0F,     // mbPerFile (compliant)
        1.0F,     // gbCap (compliant)
        16U,      // maxFiles (compliant)
        512L,     // minBytes (compliant)
        0X00FFU   // indexMask (compliant)
    };

    const std::uint64_t fileBytes = mbToBytes(cfg.mbPerFile);
    const std::uint64_t totalCap  = gbToBytes(cfg.gbCap);

    std::uint64_t maxByCap = std::max<std::uint64_t>(1U, totalCap / std::max<std::uint64_t>(1U, fileBytes)); // compliant
    const std::uint32_t allowed = static_cast<std::uint32_t>(std::min<std::uint64_t>(cfg.maxFiles, maxByCap));

    std::uint32_t startIndex = 0U; // compliant
    std::vector<std::uint64_t> sizes(allowed, 0U); // compliant

    for (std::uint32_t i = 0U; i < allowed; ++i) { // compliant
        sizes[i] = fileBytes + static_cast<std::uint64_t>(i) * 4096U + 128U; // compliant
    }

    std::uint32_t current = startIndex & cfg.indexMask;
    std::uint32_t next    = (current + 1U) & cfg.indexMask; // compliant

    const float overheadFrac = 0.02F; // compliant
    const std::uint64_t threshold = static_cast<std::uint64_t>(fileBytes * (1.0F + overheadFrac)); // compliant

    std::cout << "Allowed files: " << allowed << "\n";
    std::cout << "Per-file bytes: " << fileBytes << ", cap bytes: " << totalCap << "\n";
    std::cout << "Current index: " << current << ", Next index: " << next << "\n";

    for (std::uint32_t i = 0U; i < allowed; ++i) { // compliant
        const bool rotate = (sizes[i] >= std::max<std::uint64_t>(threshold, static_cast<std::uint64_t>(cfg.minBytes)));
        std::cout << "File[" << i << "]: size=" << sizes[i]
                  << " rotate=" << (rotate ? "yes" : "no") << "\n";
    }

    return 0;
}