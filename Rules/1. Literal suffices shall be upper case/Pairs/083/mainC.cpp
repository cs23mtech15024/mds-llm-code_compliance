// Context: Robotic arm torque balance calibration

// ------ Compliant Program (083_c.cpp)
// Context: Robotic arm torque balance calibration
// Rule: MISRA C++ 2-13-4 — uppercase suffixes (C)

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

namespace app_083 {
    // Seed literals (C): 2.75F, 5U, 90L
    constexpr float kBalance = 2.75F; // C
    constexpr unsigned kJoints = 5U;  // C
    constexpr long kIndex = 90L;      // C

    struct Joint {
        float torque;
        float desired;
    };

    void adjust(Joint& j) {
        float diff = j.desired - j.torque;
        j.torque += diff * kBalance * 0.01F; // C
    }

    void run() {
        std::vector<Joint> joints(kJoints, {0.0F, 1.0F}); // C
        for (unsigned iter = 0U; iter < 300U; ++iter) { // C
            for (auto& j : joints) adjust(j);
            if (iter % 50U == 0U) {
                float avg = 0.0F; // C
                for (auto& j : joints) avg += j.torque;
                avg /= static_cast<float>(joints.size());
                std::cout << "[083] iter=" << iter << " avgT=" << std::fixed << std::setprecision(3)
                          << avg << '\n';
            }
        }
        std::cout << "INDEX=" << kIndex << '\n';
    }
}

int main() {
    app_083::run();
    return 0;
}
