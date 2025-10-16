// seed_001_c.cpp
// Seed: Non-compliant: float opacity = 0.43f;   // Compliant: float opacity = 0.43F
// Rule: MISRA C++ 2-13-4 — literal suffixes shall be upper case.
// Fix: uses uppercase 'F' in the float literal.

#include <iostream>

struct Layer {
    void SetOpacity(float v) { std::cout << "opacity=" << v << "\n"; }
};

int main() {
    Layer controls_scrim_layer;

    // Compliant: uppercase 'F' suffix
    float initial_opacity = 0.43F;

    // Apply and show
    controls_scrim_layer.SetOpacity(initial_opacity);

    // Same logic as NC; only literal-case change
    if (initial_opacity > 0.0F) { // uppercase float suffix in comparison, too
        std::cout << "visible\n";
    } else {
        std::cout << "hidden\n";
    }
    return 0;
}