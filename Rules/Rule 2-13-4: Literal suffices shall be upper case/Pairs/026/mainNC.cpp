// ------ Non-Compliant (Seed 026)
// Context: Filesystem — rotate logs when current file size exceeds thresholds.
//          Computes byte thresholds from MB/GB factors, applies index mask, and prints plan.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violations: lowercase 'f', 'u', and 'l' suffixes; lowercase hex digits.

#include <iostream>
#include <iomanip>
#include <cstdint>
#include <string>
#include <vector>
#include <algorithm>

struct RotationCfg {
    float  mbPerFile;       // size of each log chunk in MB
    float  gbCap;           // total cap in GB
    uint32_t maxFiles;      // circular file count
    long   minBytes;        // minimum file size before rotation (bytes)
    uint32_t indexMask;     // mask for index wrapping
};

static std::uint64_t mbToBytes(float mb) {
    // 1 MB = 1024 * 1024 bytes
    return static_cast<std::uint64_t>(mb * 1024.0f * 1024.0f); // non-compliant: 1024.0f
}

static std::uint64_t gbToBytes(float gb) {
    // 1 GB = 1024 * 1024 * 1024 bytes
    return static_cast<std::uint64_t>(gb * 1024.0f * 1024.0f * 1024.0f); // non-compliant
}

int main() {
    const RotationCfg cfg{
        8.0f,     // mbPerFile (non-compliant)
        1.0f,     // gbCap (non-compliant)
        16u,      // maxFiles (non-compliant)
        512l,     // minBytes (non-compliant)
        0x00ffu   // indexMask (non-compliant)
    };

    const std::uint64_t fileBytes = mbToBytes(cfg.mbPerFile);
    const std::uint64_t totalCap  = gbToBytes(cfg.gbCap);

    // Compute how many files we can keep under the cap.
    std::uint64_t maxByCap = std::max<std::uint64_t>(1u, totalCap / std::max<std::uint64_t>(1u, fileBytes)); // 1u non-compliant
    const std::uint32_t allowed = static_cast<std::uint32_t>(std::min<std::uint64_t>(cfg.maxFiles, maxByCap));

    // Simulate a few rotations
    std::uint32_t startIndex = 0u; // non-compliant
    std::vector<std::uint64_t> sizes(allowed, 0u); // non-compliant

    for (std::uint32_t i = 0u; i < allowed; ++i) { // 0u non-compliant
        // pretend each file has incremental growth plus a tiny overhead
        sizes[i] = fileBytes + static_cast<std::uint64_t>(i) * 4096u + 128u; // 4096u/128u non-compliant
    }

    // Decide next rotation target given current index
    std::uint32_t current = startIndex & cfg.indexMask;
    std::uint32_t next    = (current + 1u) & cfg.indexMask; // 1u non-compliant

    // Rotation condition: current file exceeded threshold and at least minBytes written
    const float overheadFrac = 0.02f; // non-compliant
    const std::uint64_t threshold = static_cast<std::uint64_t>(fileBytes * (1.0f + overheadFrac)); // non-compliant

    std::cout << "Allowed files: " << allowed << "\n";
    std::cout << "Per-file bytes: " << fileBytes << ", cap bytes: " << totalCap << "\n";
    std::cout << "Current index: " << current << ", Next index: " << next << "\n";

    for (std::uint32_t i = 0u; i < allowed; ++i) { // 0u non-compliant
        const bool rotate = (sizes[i] >= std::max<std::uint64_t>(threshold, static_cast<std::uint64_t>(cfg.minBytes)));
        std::cout << "File[" << i << "]: size=" << sizes[i]
                  << " rotate=" << (rotate ? "yes" : "no") << "\n";
    }

    return 0;
}