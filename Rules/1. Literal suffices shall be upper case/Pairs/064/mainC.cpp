// Context: Submarine ballast control depth stabilizer

// ------ Compliant Program (064_c.cpp)
// Context: Submarine ballast control depth stabilizer
// Rule: MISRA C++ 2-13-4
// Fix: uses 1.5F, 20U, 400L

#include <iostream>
#include <iomanip>

namespace app_064 {
    constexpr float    depthFactor = 1.5F;  // C
    constexpr unsigned valveDelay  = 20U;   // C
    constexpr long     refDepth    = 400L;  // C

    struct Depth { float z; float vz; };

    float pump_cmd(float e, float vz) {
        return depthFactor * e - 0.2F * vz; // C
    }

    void run() {
        Depth s{0.0F, 0.0F}; // C
        const float dt = 0.05F; // C
        for (unsigned t = 0U; t < 200U; ++t) {
            float ref = static_cast<float>(refDepth) * 0.01F; // C
            float e = ref - s.z;
            float u = pump_cmd(e, s.vz);
            s.vz += u * dt;
            s.z  += s.vz * dt;
            if ((t % valveDelay) == 0U)
                std::cout << "[064] t=" << t << " z=" << std::fixed
                          << std::setprecision(2) << s.z << " vz=" << s.vz << "\n";
        }
    }
}

int main(){ app_064::run(); return 0; }
