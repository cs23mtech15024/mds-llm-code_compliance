// ------ Compliant
// Seed: Non-compliant: const int a = 0l;   // Compliant: const int a = 0L
// Context: Embedded watchdog reset procedure that logs delays to a file.
// Violation: lowercase 'l' suffix (ambiguous in critical code).
// Source: MathWorks / Polyspace (MISRA C++ Rule 2-13-4) and PVS-Studio guidance on lowercase literal suffixes. :contentReference[oaicite:1]{index=1}

#include <fstream>
#include <iostream>
#include <thread>
#include <chrono>
#include <string>

namespace drdo {
    // Simulated platform API (minimal, testable, standard headers only)
    inline void hardwareReset() {
        // In real firmware this would toggle a watchdog or reset line.
        std::cout << "[C] hardwareReset(): device reset invoked\n";
    }
}

// compliant implementation: seed corrected to '0L' (uppercase L)
void performReset_C(const std::string &logPath = "drdo_reset.log") {
    constexpr unsigned RESET_DELAY_MS = 0L; // C: uppercase 'L' (compliant)
    std::ofstream log(logPath, std::ios::app);
    if (!log) {
        std::cerr << "[C] Log open failed\n";
        return;
    }
    log << "[C] Reset delay (ms): " << RESET_DELAY_MS << "\n";
    // Simulate waiting for reset (uses RESET_DELAY_MS)
    std::this_thread::sleep_for(std::chrono::milliseconds(RESET_DELAY_MS));
    drdo::hardwareReset();
    log << "[C] Watchdog reset performed\n";
    log.close();
}

int main() {
    std::cout << "[C] Starting performReset_C()\n";
    performReset_C();
    std::cout << "[C] Done\n";
    return 0;
}
