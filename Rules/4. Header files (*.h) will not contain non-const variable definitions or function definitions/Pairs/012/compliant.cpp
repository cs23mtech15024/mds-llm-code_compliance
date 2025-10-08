// ------ Compliant
// Seed: Non-compliant header: bool featureEnabled = true;   // Compliant header: extern bool featureEnabled;
// Context: Header contains only declarations; definitions moved to implementation.
// Provenance:
//   - StackOverflow Q#1433204: "How do I use extern to share variables between source files?" (https://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files).
//   - cppreference: One Definition Rule / Definitions and ODR (https://en.cppreference.com/w/cpp/language/definition).
//   - PVS-Studio / static-analysis guidance: header best practices.
// Compliance: Header-like region contains only declarations (extern and prototype); definitions are in the implementation section.

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <string>

// ------------------- good_header.h (inlined here for demo) -------------------
// COMPLIANT: header contains only declarations (no non-const definitions)
//
// Seed (header declaration): extern bool featureEnabled;
extern bool featureEnabled; // declaration only

// Function prototype only (no definition in header)
void enable_feature_for(const std::string &component);
// ---------------------------------------------------------------------------

// Implementation section: definitions moved out of header area (compliant)
bool featureEnabled = true; // COMPLIANT: definition in implementation file

void enable_feature_for(const std::string &component) {
    featureEnabled = true;
    std::cout << "[C] enable_feature_for: " << component
              << " featureEnabled=" << (featureEnabled ? "true" : "false") << '\n';
}

void simulate_components() {
    std::vector<std::string> comps = {"SensorA", "SensorB", "Comm"};
    for (const auto &c : comps) {
        enable_feature_for(c);
        std::this_thread::sleep_for(std::chrono::milliseconds(4));
    }
}

int main() {
    simulate_components();
    std::cout << "[C] final featureEnabled = " << (featureEnabled ? "true" : "false") << '\n';
    return 0;
}