// ------ Non-Compliant
// Seed: Non-compliant header: int g_value = 42;   // Compliant header: extern int g_value;
// Context: Demonstrates a header that incorrectly defines a non-const global and a non-inline function.
// Provenance:
//   - cppreference: One Definition Rule / Definitions and ODR. https://en.cppreference.com/w/cpp/language/definition.  [oai_citation:2‡en.cppreference.com](https://en.cppreference.com/w/cpp/language/definition.html?utm_source=chatgpt.com)
//   - StackOverflow: "Multiple definition error on variable that is declared and defined in header file". https://stackoverflow.com/questions/55238194/multiple-definition-error-on-variable-that-is-declared-and-defined-in-header-fil.  [oai_citation:3‡Stack Overflow](https://stackoverflow.com/questions/55238194/multiple-definition-error-on-variable-that-is-declared-and-defined-in-header-fil?utm_source=chatgpt.com)
// Violation: The header-like region below defines a non-const variable and a non-inline function — this can produce multiple-definition errors and violates MISRA C++ Rule 8-5-2.

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <numeric>

// ------------------- bad_header.h (inlined here for demo) -------------------
// NON-COMPLIANT: header contains definitions (violates Rule 8-5-2)
//
// Seed (must appear in header): int g_value = 42;
int g_value = 42; // NON-COMPLIANT: non-const global definition in header

// NON-COMPLIANT: function definition in header (non-inline)
int compute_and_add(int x) {
    // uses header-defined global
    int r = (x * 3 + g_value) % 100;
    std::cout << "[NC] compute_and_add(" << x << ") => " << r << '\n';
    return r;
}
// ---------------------------------------------------------------------------

int main() {
    std::vector<int> inputs = {1, 5, 7};
    int total = 0;
    for (int v : inputs) {
        total += compute_and_add(v);
        std::this_thread::sleep_for(std::chrono::milliseconds(4));
    }
    std::cout << "[NC] total=" << total << " g_value=" << g_value << '\n';
    return 0;
}