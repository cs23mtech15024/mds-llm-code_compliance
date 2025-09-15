// Title: Free function defined but never called (Non-compliant — Rule 0-1-10)
// Seed source: 01_free_function_never_called.cpp (from /mnt/data/Seed_Rule_0_1_10)
// Pattern inspired by OSS diagnostics: GCC/Clang -Wunused-function, Cppcheck 'unusedFunction'
#include <iostream>

void helper_format() { std::cout << "fmt\n"; } // defined, NEVER called

int main() {
    std::cout << "run" << std::endl;
    // Rationale: A defined free function is never invoked; violates MISRA C++:2008 Rule 0-1-10.
    return 0;
}
