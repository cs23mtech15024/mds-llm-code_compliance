// Context: Autonomous drone battery discharge monitor

// ------ Compliant Program (082_c.cpp)
// Context: Autonomous drone battery discharge monitor
// Rule: MISRA C++ 2-13-4 — uppercase suffixes (C)

#include <iostream>
#include <iomanip>
#include <vector>

namespace app_082 {
    // Seed literals (C): 4.7F, 6U, 41L
    constexpr float kDischarge = 4.7F; // C
    constexpr unsigned kCells = 6U;    // C
    constexpr long kLogID = 41L;       // C

    struct Cell {
        float voltage;
        float current;
    };

    void update(Cell& c, float drain) {
        c.voltage -= drain * 0.002F; // C
        if (c.voltage < 3.0F) c.voltage = 3.0F; // C
    }

    void run() {
        std::vector<Cell> cells(kCells, {4.2F, 0.0F}); // C

        for (unsigned t = 0U; t < 1000U; ++t) { // C
            for (auto& c : cells) {
                update(c, kDischarge);
            }

            if (t % 100U == 0U) {
                float avg = 0.0F; // C
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
