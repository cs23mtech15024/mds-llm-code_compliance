// Seed 030 (Non-Compliant)
// Context: Embedded Systems — ADC voltage scaling constants for sensor input.
// Seed: Non-compliant: const float VREF = 3.3f; const unsigned MAX_ADC = 1023u;   // Compliant: const float VREF = 3.3F; const unsigned MAX_ADC = 1023U
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violation: Uses lowercase 'f' and 'u' suffixes for literals.

#include <iostream>

int main() {
    const float VREF = 3.3f;      // non-compliant
    const unsigned MAX_ADC = 1023u; // non-compliant
    std::cout << VREF << " " << MAX_ADC << "\n";
    return 0;
}