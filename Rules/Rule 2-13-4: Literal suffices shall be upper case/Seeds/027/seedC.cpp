// Seed 027 (Compliant)
// Context: Networking — exponential backoff constants for HTTP retry scheduler.
// Seed: Non-compliant: const unsigned maxRetries = 3u;   // Compliant: const unsigned maxRetries = 3U
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.

#include <iostream>

int main() {
    const unsigned maxRetries = 3U; // compliant
    std::cout << maxRetries << "\n";
    return 0;
}