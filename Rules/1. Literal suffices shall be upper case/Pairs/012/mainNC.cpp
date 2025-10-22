// ------ Non-Compliant (Seed 012)
// Context: Temperature conversion table generator using floating constants.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.

#include <iostream>
#include <iomanip>

float to_fahrenheit(float c) {
    return (c * 1.8f) + 32.0f; // lower-case 'f' suffixes → non-compliant
}

int main() {
    std::cout << "Celsius to Fahrenheit Conversion Table\n";
    std::cout << std::fixed << std::setprecision(2);

    for (float c = -20.0f; c <= 40.0f; c += 10.0f) {
        std::cout << std::setw(6) << c << " °C = "
                  << std::setw(7) << to_fahrenheit(c) << " °F\n";
    }

    return 0;
}