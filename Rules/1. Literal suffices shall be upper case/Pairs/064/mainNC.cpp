// Context: Submarine ballast control depth stabilizer

// ------ Non-Compliant Program (064_nc.cpp)
// Context: Submarine ballast control depth stabilizer
// Rule: MISRA C++ 2-13-4
// Violation: uses 1.5f, 20u, 400l

#include <iostream>
#include <iomanip>

namespace app_064 {
    constexpr float    depthFactor = 1.5f;  // NC
    constexpr unsigned valveDelay  = 20u;   // NC
    constexpr long     refDepth    = 400l;  // NC

    struct Depth { float z; float vz; };

    float pump_cmd(float e, float vz) {
        return depthFactor * e - 0.2f * vz; // NC
    }

    void run() {
        Depth s{0.0f, 0.0f}; // NC
        const float dt = 0.05f; // NC
        for (unsigned t = 0u; t < 200u; ++t) { // NC
            float ref = static_cast<float>(refDepth) * 0.01f; // NC
            float e = ref - s.z;
            float u = pump_cmd(e, s.vz);
            s.vz += u * dt;
            s.z  += s.vz * dt;
            if ((t % valveDelay) == 0u)
                std::cout << "[064] t=" << t << " z=" << std::fixed
                          << std::setprecision(2) << s.z << " vz=" << s.vz << "\n";
        }
    }
}

int main(){ app_064::run(); return 0; }
