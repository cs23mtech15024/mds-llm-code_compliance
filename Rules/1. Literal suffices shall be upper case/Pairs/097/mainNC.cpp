// Context: Aerospace control moment gyroscope tester

// ------ Non-Compliant Program (097_nc.cpp)
// Context: Aerospace control moment gyroscope tester
// Rule: MISRA C++ 2-13-4 — lowercase literal suffixes used intentionally (NC)

#include <iostream>
#include <iomanip>
#include <array>
#include <cmath>

namespace app_097 {
    // Seed literals (NC): 1.1f, 8u, 500l
    constexpr float kGain = 1.1f;    // NC
    constexpr unsigned kChannels = 8u; // NC
    constexpr long kTag = 500l;      // NC

    struct CMG { float torque; float error; };

    void testCMG(CMG &c, float input) {
        float desired = input * kGain;
        c.error = desired - c.torque;
        c.torque += c.error * 0.02f; // NC
    }

    void run() {
        std::array<CMG, kChannels> cmg{};
        for (unsigned i = 0u; i < kChannels; ++i) cmg[i].torque = 10.0f + static_cast<float>(i);
        for (unsigned t = 0u; t < 250u; ++t) { // NC
            float input = std::sin(0.03f * static_cast<float>(t)); // NC
            for (auto &c : cmg) testCMG(c, input);
            if ((t % 50u) == 0u) {
                std::cout << "[097] t=" << t << " torque=" << cmg[0].torque
                          << " tag=" << kTag << '\n';
            }
        }
    }
}

int main() {
    app_097::run();
    return 0;
}
