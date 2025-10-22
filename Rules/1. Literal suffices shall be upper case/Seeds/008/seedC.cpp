// Context: Sensor calibration constants with uppercase 'E' in scientific literals.
// Seed: Non-compliant: const double scale = 1.0e-3;   // Compliant: const double scale = 1.0E-3;
// Rule: MISRA C++ 2-13-4 – Literal suffixes and exponents shall use upper case.
// Fix: Exponent indicator changed from ‘e’ to ‘E’.

#include <iostream>

int main() {
    const double scale = 1.0E-3;  // C
    const double offset = 2.5E1;  // C
    double reading = 512.0 * scale + offset;
    std::cout << "Calibrated reading: " << reading << "\n";
    return 0;
}