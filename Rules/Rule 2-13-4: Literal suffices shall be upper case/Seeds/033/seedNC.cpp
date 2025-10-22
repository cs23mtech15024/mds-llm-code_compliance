// Seed 033 (Non-Compliant)
// Context: Filesystem — log rotation thresholds & permission mask.
// Seed: Non-compliant: const float kScanInterval = 1.25f; const unsigned kMaxOpenFiles = 16u; const unsigned kPermMask = 0x7ffu; const long kLogReserve = 8l;
//        Compliant:     const float kScanInterval = 1.25F; const unsigned kMaxOpenFiles = 16U; const unsigned kPermMask = 0X7FFU; const long kLogReserve = 8L
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violation: Uses lowercase 'f'/'u'/'l' suffixes and lowercase hex digits.

#include <iostream>

int main() {
    const float kScanInterval = 1.25f;   // non-compliant
    const unsigned kMaxOpenFiles = 16u;  // non-compliant
    const unsigned kPermMask = 0x7ffu;   // non-compliant
    const long kLogReserve = 8l;         // non-compliant
    std::cout << kScanInterval << " " << kMaxOpenFiles << " "
              << kPermMask << " " << kLogReserve << "\n";
    return 0;
}