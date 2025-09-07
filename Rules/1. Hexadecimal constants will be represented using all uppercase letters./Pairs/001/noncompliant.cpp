// ------ Non-Compliant
// Seed: Non-compliant: const int a = 0l;   // Compliant: const int a = 0L
// Context: Embedded watchdog reset procedure that logs delays to a file.
// Violation: lowercase 'l' suffix (ambiguous in critical code).
// Source: MathWorks / Polyspace (MISRA C++ Rule 2-13-4) and PVS-Studio guidance on lowercase literal suffixes. :contentReference[oaicite:0]{index=0}

#include <fstream>
#include <iostream>
#include <thread>
#include <chrono>
#include <string>

namespace drdo {
    // Simulated platform API (minimal, testable, standard headers only)
    inline void hardwareReset() {
        // In real firmware this would toggle a watchdog or reset line.
        std::cout << "[NC] hardwareReset(): device reset invoked\n";
    }
}

// Non-compliant implementation: contains the seed '0l' (lowercase L)
void performReset_NC(const std::string &logPath = "drdo_reset.log") {
    constexpr unsigned RESET_DELAY_MS = 0l; // NC: lowercase 'l' suffix (seed)
    std::ofstream log(logPath, std::ios::app);
    if (!log) {
        std::cerr << "[NC] Log open failed\n";
        return;
    }
    log << "[NC] Reset delay (ms): " << RESET_DELAY_MS << "\n";
    // Simulate waiting for reset (uses RESET_DELAY_MS)
    std::this_thread::sleep_for(std::chrono::milliseconds(RESET_DELAY_MS));
    drdo::hardwareReset();
    log << "[NC] Watchdog reset performed\n";
    log.close();
}

int main() {
    std::cout << "[NC] Starting performReset_NC()\n";
    performReset_NC();
    std::cout << "[NC] Done\n";
    return 0;
}
