// seed_001_nc.cpp
// Seed: Non-compliant: float opacity = 0.43f;   // Compliant: float opacity = 0.43F
// Rule: MISRA C++ 2-13-4 — literal suffixes shall be upper case.
// Violation: uses lowercase 'f' in the float literal.

#include <iostream>

struct Layer {
    void SetOpacity(float v) { std::cout << "opacity=" << v << "\n"; }
};

int main() {
    Layer controls_scrim_layer;

    // Non-compliant: lowercase 'f' suffix
    float initial_opacity = 0.43f;

    // Apply and show
    controls_scrim_layer.SetOpacity(initial_opacity);

    // Simple check to keep the logic deterministic
    if (initial_opacity > 0.0f) { // comparison literal doesn't need suffix change
        std::cout << "visible\n";
    } else {
        std::cout << "hidden\n";
    }
    return 0;
}