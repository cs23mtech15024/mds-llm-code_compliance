// ------ Compliant
// Seed: Non-compliant header: int g_value = 42;   // Compliant header: extern int g_value;
// Context: Header contains only declarations; definitions moved into implementation.
// Provenance:
//   - cppreference: One Definition Rule / Definitions and ODR. https://en.cppreference.com/w/cpp/language/definition.  [oai_citation:4‡en.cppreference.com](https://en.cppreference.com/w/cpp/language/definition.html?utm_source=chatgpt.com)
//   - StackOverflow: "Multiple definition error on variable that is declared and defined in header file". https://stackoverflow.com/questions/55238194/multiple-definition-error-on-variable-that-is-declared-and-defined-in-header-fil.  [oai_citation:5‡Stack Overflow](https://stackoverflow.com/questions/55238194/multiple-definition-error-on-variable-that-is-declared-and-defined-in-header-fil?utm_source=chatgpt.com)
// Compliance: Header area contains only declarations (extern and prototype); global & function definitions are in the implementation section.

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <numeric>

// ------------------- good_header.h (inlined here for demo) -------------------
// COMPLIANT: header contains only declarations (no non-const definitions)
//
// Seed (header declaration): extern int g_value;
extern int g_value; // declaration only

// Function prototype only (no definition in header)
int compute_and_add(int x);
// ---------------------------------------------------------------------------

// Implementation section: definitions moved out of header area (compliant)
int g_value = 42; // COMPLIANT: definition in implementation file

int compute_and_add(int x) {
    int r = (x * 3 + g_value) % 100;
    std::cout << "[C] compute_and_add(" << x << ") => " << r << '\n';
    return r;
}

int main() {
    std::vector<int> inputs = {1, 5, 7};
    int total = 0;
    for (int v : inputs) {
        total += compute_and_add(v);
        std::this_thread::sleep_for(std::chrono::milliseconds(4));
    }
    std::cout << "[C] total=" << total << " g_value=" << g_value << '\n';
    return 0;
}