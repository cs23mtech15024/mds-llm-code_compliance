// Seed 012 (Non-Compliant)
// Context: Temperature conversion using floating constants.
// Seed: Non-compliant: const float scale = 1.8f;   // Compliant: const float scale = 1.8F
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violation: Lower-case ‘f’ suffix on floating-point literal.

#include <iostream>

int main() {
    const float scale = 1.8f;   // non-compliant literal suffix
    const float offset = 32.0f; // non-compliant literal suffix
    float celsius = 25.0f;
    float fahrenheit = (celsius * scale) + offset;
    std::cout << celsius << " °C = " << fahrenheit << " °F\n";
    return 0;
}