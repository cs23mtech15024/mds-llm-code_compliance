// Title: Free function is called at least once (Compliant — Rule 0-1-10)
// Seed source: 01 (free function) — corrected
// Pattern inspired by OSS diagnostics: GCC/Clang -Wunused-function, Cppcheck 'unusedFunction'
#include <iostream>

void helper_format() { std::cout << "fmt\n"; } // defined and USED

int main() {
    helper_format(); // actual call introduced
    std::cout << "run" << std::endl;
    // Rationale: Every defined function (helper_format) is invoked at least once; compliant.
    return 0;
}
