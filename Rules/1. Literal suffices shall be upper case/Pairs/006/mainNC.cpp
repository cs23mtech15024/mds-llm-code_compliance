// Context: A simple 2D projectile simulation uses single-precision constants with lowercase 'f' suffix.
// Rule violated: MISRA C++ 2-13-4 – Literal suffixes shall be upper case.
// Seed: Non-compliant: const float gravity = 9.81f;   // Compliant: const float gravity = 9.81F;
// Violation: All float literals use lowercase ‘f’.

#include <iostream>
#include <cmath>
#include <iomanip>

struct Projectile {
    float velocity;  // m/s
    float angle;     // degrees
    float gravity;   // m/s^2

    void simulate(float time_step, int steps) {
        float rad = angle * 3.14159f / 180.0f; // NC
        float vx = velocity * std::cos(rad);
        float vy = velocity * std::sin(rad);
        float y = 0.0f;
        float x = 0.0f;

        for (int i = 0; i < steps; ++i) {
            vy -= gravity * time_step;
            y += vy * time_step;
            x += vx * time_step;
            if (y < 0.0f) break;
        }
        std::cout << std::fixed << std::setprecision(2)
                  << "Range: " << x << " m, Height: " << y << " m\n";
    }
};

int main() {
    Projectile p{50.0f, 45.0f, 9.81f}; // NC
    p.simulate(0.016f, 6000);          // NC
    return 0;
}