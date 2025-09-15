// Title: Function template is instantiated by a call (Compliant — Rule 0-1-10)
// Seed source: 05 (function template) — corrected
#include <iostream>

template <typename T>
T clamp01(T v) { return (v < 0 ? 0 : (v > 1 ? 1 : v)); }

int main() {
    double r = clamp01(1.25); // actual call instantiates template
    std::cout << r << std::endl;
    // Rationale: The defined function template is invoked; compliant.
    return 0;
}
