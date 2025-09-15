// Title: Static member function is called (Compliant — Rule 0-1-10)
// Seed source: 11 (static member) — corrected
#include <iostream>

struct Log {
    static void verbose() { std::cout << "vvv\n"; }
    static void info()    { std::cout << "iii\n"; }
};

int main() {
    Log::verbose(); // call the previously unused function
    Log::info();
    // Rationale: All defined static members are invoked at least once; compliant.
    return 0;
}
