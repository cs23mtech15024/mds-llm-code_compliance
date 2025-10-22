// Context: Robotic arm torque balance calibration

// ------ Non-Compliant Program (083_nc.cpp)
// Context: Robotic arm torque balance calibration
// Rule: MISRA C++ 2-13-4 — lowercase suffixes intentionally (NC)

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

namespace app_083 {
    // Seed literals (NC): 2.75f, 5u, 90l
    constexpr float kBalance = 2.75f; // NC
    constexpr unsigned kJoints = 5u;  // NC
    constexpr long kIndex = 90l;      // NC

    struct Joint {
        float torque;
        float desired;
    };

    void adjust(Joint& j) {
        float diff = j.desired - j.torque;
        j.torque += diff * kBalance * 0.01f; // NC
    }

    void run() {
        std::vector<Joint> joints(kJoints, {0.0f, 1.0f}); // NC
        for (unsigned iter = 0u; iter < 300u; ++iter) { // NC
            for (auto& j : joints) adjust(j);
            if (iter % 50u == 0u) {
                float avg = 0.0f; // NC
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
