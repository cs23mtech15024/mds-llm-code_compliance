// ------ Non-Compliant
// Seed: Non-compliant header: void logData() { ... }   // Compliant header: inline void logData() { ... }
// Context: Demonstrates that non-inline function definitions in headers violate MISRA Rule 8-5-2.
// Provenance: cppreference inline functions; StackOverflow discussion on header-based inline usage; MISRA rationale on ODR violations.
// Violation: Header contains a full non-inline function definition, which can cause multiple-definition errors if the header is included in multiple translation units.

#include <iostream>
#include <vector>
#include <numeric>
#include <thread>
#include <chrono>

// ---------------- bad_header.h (inlined here) ----------------
// NON-COMPLIANT: full non-inline definition in header (violates Rule 8-5-2)
//
// Seed: void logData() { ... }
void logData(const std::vector<int>& v) {
    auto avg = v.empty() ? 0.0 : static_cast<double>(std::accumulate(v.begin(), v.end(), 0)) / v.size();
    std::cout << "[NC] logData: elements=" << v.size() << " avg=" << avg << '\n';
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
    std::cout << "[NC] Simulation complete\n";
    return 0;
}