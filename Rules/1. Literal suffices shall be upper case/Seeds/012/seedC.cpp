// Seed 012 (Compliant)
// Context: Temperature conversion using floating constants.
// Seed: Non-compliant: const float scale = 1.8f;   // Compliant: const float scale = 1.8F
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.

#include <iostream>

int main() {
    const float scale = 1.8F;   // compliant literal suffix
    const float offset = 32.0F; // compliant literal suffix
    float celsius = 25.0F;
    float fahrenheit = (celsius * scale) + offset;
    std::cout << celsius << " °C = " << fahrenheit << " °F\n";
    return 0;
}