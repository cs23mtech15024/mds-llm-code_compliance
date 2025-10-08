// ------ Compliant
// Seed: Non-compliant header: void logData() { ... }   // Compliant header: inline void logData() { ... }
// Context: Demonstrates that inline function definitions are permitted in headers.
// Provenance: cppreference inline functions; StackOverflow discussion on header-based inline usage; MISRA rationale on ODR violations.
// Compliance: The function `logData` is marked inline, which allows safe inclusion in headers per Rule 8-5-2.

#include <iostream>
#include <vector>
#include <numeric>
#include <thread>
#include <chrono>

// ---------------- good_header.h (inlined here) ----------------
// COMPLIANT: inline function definition in header
//
// Seed: inline void logData() { ... }
inline void logData(const std::vector<int>& v) {
    auto avg = v.empty() ? 0.0 : static_cast<double>(std::accumulate(v.begin(), v.end(), 0)) / v.size();
    std::cout << "[C] logData: elements=" << v.size() << " avg=" << avg << '\n';
}
// ----------------------------------------------------------------

void simulateTelemetry() {
    std::vector<int> sensor = {10, 20, 30, 40, 50};
    logData(sensor);
    std::this_thread::sleep_for(std::chrono::milliseconds(3));
    sensor.push_back(60);
    logData(sensor);
}

int main() {
    simulateTelemetry();
    std::cout << "[C] Simulation complete\n";
    return 0;
}