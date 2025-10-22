// Seed 041 (Non-Compliant)
// Context: Audio Signal Processing — Reverb Decay Constant and Buffer Size
// Seed: Non-compliant: const float kDecay = 0.65f; const unsigned kBufferSize = 4096u; const long kMaxDelay = 2400l;
//         Compliant:    const float kDecay = 0.65F; const unsigned kBufferSize = 4096U; const long kMaxDelay = 2400L
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violation: Lowercase 'f', 'u', and 'l' suffixes.

#include <iostream>

int main() {
    const float kDecay = 0.65f;       // non-compliant
    const unsigned kBufferSize = 4096u; // non-compliant
    const long kMaxDelay = 2400l;     // non-compliant

    std::cout << "Reverb decay: " << kDecay 
              << ", Buffer size: " << kBufferSize 
              << ", Max delay: " << kMaxDelay << "\n";
    return 0;
}