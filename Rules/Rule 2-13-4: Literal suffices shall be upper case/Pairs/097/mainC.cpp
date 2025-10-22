// Context: Aerospace control moment gyroscope tester

// ------ Compliant Program (097_c.cpp)
// Context: Aerospace control moment gyroscope tester
// Rule: MISRA C++ 2-13-4 — uppercase literal suffixes (C)

#include <iostream>
#include <iomanip>
#include <array>
#include <cmath>

namespace app_097 {
    // Seed literals (C): 1.1F, 8U, 500L
    constexpr float kGain = 1.1F;    // C
    constexpr unsigned kChannels = 8U; // C
    constexpr long kTag = 500L;      // C

    struct CMG { float torque; float error; };

    void testCMG(CMG &c, float input) {
        float desired = input * kGain;
        c.error = desired - c.torque;
        c.torque += c.error * 0.02F; // C
    }

    void run() {
        std::array<CMG, kChannels> cmg{};
        for (unsigned i = 0U; i < kChannels; ++i) cmg[i].torque = 10.0F + static_cast<float>(i);
        for (unsigned t = 0U; t < 250U; ++t) { // C
            float input = std::sin(0.03F * static_cast<float>(t)); // C
            for (auto &c : cmg) testCMG(c, input);
            if ((t % 50U) == 0U) {
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
