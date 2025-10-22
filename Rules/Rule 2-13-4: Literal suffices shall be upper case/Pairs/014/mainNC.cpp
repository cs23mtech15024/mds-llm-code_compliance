// ------ Non-Compliant (Seed 014)
// Context: Simple gravity simulation to calculate falling object's velocity.
// Reference: MISRA C++ 2008 Rule 2-13-4 — Literal suffixes shall be upper case.
// Violation: Lowercase 'f' used on float literals.

#include <iostream>
#include <iomanip>

class GravitySim {
    float g; // gravitational acceleration
public:
    explicit GravitySim(float gravity = 9.81f) : g(gravity) {}
    float velocity(float time) const { return g * time; }
    void simulate(float duration) const {
        std::cout << "Simulating free fall for " << duration << " seconds:\n";
        for (float t = 0.0f; t <= duration; t += 0.5f) {
            std::cout << std::fixed << std::setprecision(2)
                      << "t=" << t << "s, v=" << velocity(t) << " m/s\n";
        }
    }
};

int main() {
    GravitySim sim;
    sim.simulate(3.0f);
    return 0;
}