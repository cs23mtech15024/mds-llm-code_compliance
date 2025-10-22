// ------ Compliant (Seed 012)
// Context: Temperature conversion table generator using floating constants.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.

#include <iostream>
#include <iomanip>

float to_fahrenheit(float c) {
    return (c * 1.8F) + 32.0F; // upper-case 'F' suffixes → compliant
}

int main() {
    std::cout << "Celsius to Fahrenheit Conversion Table\n";
    std::cout << std::fixed << std::setprecision(2);

    for (float c = -20.0F; c <= 40.0F; c += 10.0F) {
        std::cout << std::setw(6) << c << " °C = "
                  << std::setw(7) << to_fahrenheit(c) << " °F\n";
    }

    return 0;
}