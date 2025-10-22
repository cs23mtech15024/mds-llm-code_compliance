// Seed 021 (Compliant)
// Context: Networking — Simulating packet loss probability for a data stream.
// Seed: Non-compliant: const float lossRate = 0.05f;   // Compliant: const float lossRate = 0.05F
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.

#include <iostream>

int main() {
    const float lossRate = 0.05F; // compliant
    std::cout << lossRate << "\n";
    return 0;
}