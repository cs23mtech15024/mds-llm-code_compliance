// Context: Sensor calibration constants with lowercase 'e' in scientific literals.
// Seed: Non-compliant: const double scale = 1.0e-3;   // Compliant: const double scale = 1.0E-3;
// Rule: MISRA C++ 2-13-4 – Literal suffixes and exponents shall use upper case.
// Violation: Lowercase ‘e’ used in scientific notation.

#include <iostream>

int main() {
    const double scale = 1.0e-3;  // NC
    const double offset = 2.5e1;  // NC
    double reading = 512.0 * scale + offset;
    std::cout << "Calibrated reading: " << reading << "\n";
    return 0;
}