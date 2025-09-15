// Title: Function taking references defined but never called (Non-compliant — Rule 0-1-10)
// Seed source: 10_friend_function_never_used.cpp
#include <iostream>

void swap2(int& a, int& b) { int t = a; a = b; b = t; } // defined, NEVER called

int main() {
    int x = 1, y = 2;
    std::cout << x + y << std::endl;
    // Rationale: swap2 is defined but never invoked; non-compliant.
    return 0;
}
