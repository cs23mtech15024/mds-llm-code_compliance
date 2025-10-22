// Context: Autonomous drone battery discharge monitor

// ------ Non-Compliant Program (082_nc.cpp)
// Context: Autonomous drone battery discharge monitor
// Rule: MISRA C++ 2-13-4 — lowercase suffixes intentionally (NC)

#include <iostream>
#include <iomanip>
#include <vector>

namespace app_082 {
    // Seed literals (NC): 4.7f, 6u, 41l
    constexpr float kDischarge = 4.7f; // NC
    constexpr unsigned kCells = 6u;    // NC
    constexpr long kLogID = 41l;       // NC

    struct Cell {
        float voltage;
        float current;
    };

    void update(Cell& c, float drain) {
        c.voltage -= drain * 0.002f; // NC
        if (c.voltage < 3.0f) c.voltage = 3.0f; // NC
    }

    void run() {
        std::vector<Cell> cells(kCells, {4.2f, 0.0f}); // NC

        for (unsigned t = 0u; t < 1000u; ++t) { // NC
            for (auto& c : cells) {
                update(c, kDischarge);
            }

            if (t % 100u == 0u) {
                float avg = 0.0f; // NC
                for (const auto& c : cells) avg += c.voltage;
                avg /= static_cast<float>(cells.size());
                std::cout << "[082] t=" << t << " avgV=" << std::fixed << std::setprecision(3)
                          << avg << '\n';
            }
        }
        std::cout << "LOGID=" << kLogID << '\n';
    }
}

int main() {
    app_082::run();
    return 0;
}
