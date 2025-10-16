// ------ Non-Compliant
// Seed: Non-compliant header: bool featureEnabled = true;   // Compliant header: extern bool featureEnabled;
// Context: Header incorrectly contains a non-const global flag and a non-inline function definition.
// Provenance:
//   - StackOverflow Q#1433204: "How do I use extern to share variables between source files?" (https://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files).
//   - cppreference: One Definition Rule / Definitions and ODR (https://en.cppreference.com/w/cpp/language/definition).
//   - PVS-Studio / static-analysis guidance: header best practices.
// Violation: Header contains a non-const variable definition and a non-inline function definition (violates MISRA C++ Rule 8-5-2).

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <string>

// ------------------- bad_header.h (inlined here for demo) -------------------
// NON-COMPLIANT: header contains definitions (violates Rule 8-5-2)
//
// Seed (must appear in header): bool featureEnabled = true;
bool featureEnabled = true; // NON-COMPLIANT: non-const global definition in header

// NON-COMPLIANT: non-inline function definition in header (should be prototype only)
void enable_feature_for(const std::string &component) {
    // deterministic behavior: flip flag and print
    featureEnabled = true;
    std::cout << "[NC] enable_feature_for: " << component
              << " featureEnabled=" << (featureEnabled ? "true" : "false") << '\n';
}
// ---------------------------------------------------------------------------

void simulate_components() {
    std::vector<std::string> comps = {"SensorA", "SensorB", "Comm"};
    for (const auto &c : comps) {
        enable_feature_for(c);
        std::this_thread::sleep_for(std::chrono::milliseconds(4));
    }
}

int main() {
    // simulate enabling the feature across components
    simulate_components();
    std::cout << "[NC] final featureEnabled = " << (featureEnabled ? "true" : "false") << '\n';
    return 0;
}