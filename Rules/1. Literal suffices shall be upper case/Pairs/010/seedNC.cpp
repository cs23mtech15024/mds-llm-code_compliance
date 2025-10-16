// Context: Networking – default buffer sizes and flag masks with lower-case suffixes.
// Seed: Non-compliant: const unsigned recv_buf = 4096u;   // Compliant: const unsigned recv_buf = 4096U
// Rule: MISRA C++ 2-13-4 — Literal suffixes shall be upper case.

#include <iostream>
int main() {
    const unsigned recv_buf = 4096u; // NC: 'u' should be 'U'
    std::cout << recv_buf << "\n";
    return 0;
}