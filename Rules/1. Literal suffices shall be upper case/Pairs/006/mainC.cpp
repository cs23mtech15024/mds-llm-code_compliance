// Context: A simple 2D projectile simulation uses single-precision constants with uppercase 'F' suffix.
// Rule satisfied: MISRA C++ 2-13-4 – Literal suffixes shall be upper case.
// Seed: Non-compliant: const float gravity = 9.81f;   // Compliant: const float gravity = 9.81F;
// Fix: All float literals now use uppercase ‘F’.

#include <iostream>
#include <cmath>
#include <iomanip>

struct Projectile {
    float velocity;  // m/s
    float angle;     // degrees
    float gravity;   // m/s^2

    void simulate(float time_step, int steps) {
        float rad = angle * 3.14159F / 180.0F; // C
        float vx = velocity * std::cos(rad);
        float vy = velocity * std::sin(rad);
        float y = 0.0F;
        float x = 0.0F;

        for (int i = 0; i < steps; ++i) {
            vy -= gravity * time_step;
            y += vy * time_step;
            x += vx * time_step;
            if (y < 0.0F) break;
        }
        std::cout << std::fixed << std::setprecision(2)
                  << "Range: " << x << " m, Height: " << y << " m\n";
    }
};

int main() {
    Projectile p{50.0F, 45.0F, 9.81F}; // C
    p.simulate(0.016F, 6000);          // C
    return 0;
}