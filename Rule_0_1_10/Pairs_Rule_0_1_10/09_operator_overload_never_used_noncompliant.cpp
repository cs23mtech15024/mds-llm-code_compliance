// Title: Operator overload defined but never used (Non-compliant — Rule 0-1-10)
// Seed source: 05_function_template_never_called.cpp
#include <iostream>

struct Vec2 { int x; int y; };

Vec2 operator+(const Vec2& a, const Vec2& b) { // defined, NEVER used
    Vec2 r = { a.x + b.x, a.y + b.y };
    return r;
}

int main() {
    Vec2 a = {1,2}, b = {3,4};
    (void)a; (void)b;
    std::cout << "noop" << std::endl;
    // Rationale: operator+ is never invoked; non-compliant.
    return 0;
}
