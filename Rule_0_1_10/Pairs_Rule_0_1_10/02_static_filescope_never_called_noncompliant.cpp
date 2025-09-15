// Title: File-scope static function never called (Non-compliant — Rule 0-1-10)
// Seed source: 01_placeholder_never_called.cpp
// Pattern inspired by OSS diagnostics: -Wunused-function / 'unusedFunction'
#include <iostream>

static void internal_probe() { std::cout << "probe\n"; } // defined, NEVER called

int main() {
    std::cout << "init" << std::endl;
    // Rationale: internal_probe has internal linkage and is never invoked; non-compliant.
    return 0;
}
