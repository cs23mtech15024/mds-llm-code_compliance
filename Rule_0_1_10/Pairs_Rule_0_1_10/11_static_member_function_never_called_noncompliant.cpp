// Title: Static member function defined but never called (Non-compliant — Rule 0-1-10)
// Seed source: 06_anonymous_namespace_never_called.cpp
#include <iostream>

struct Log {
    static void verbose() { std::cout << "vvv\n"; } // defined, NEVER called
    static void info()    { std::cout << "iii\n"; }
};

int main() {
    Log::info();
    // Rationale: Log::verbose is never called; non-compliant.
    return 0;
}
