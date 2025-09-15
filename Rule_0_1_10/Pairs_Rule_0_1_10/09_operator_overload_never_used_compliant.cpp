// Title: Operator overload is exercised (Compliant — Rule 0-1-10)
// Seed source: 09 (operator+) — corrected
#include <iostream>

struct Vec2 { int x; int y; };

Vec2 operator+(const Vec2& a, const Vec2& b) {
    Vec2 r = { a.x + b.x, a.y + b.y };
    return r;
}

int main() {
    Vec2 a = {1,2}, b = {3,4};
    Vec2 c = a + b; // invokes operator+
    std::cout << c.x << "," << c.y << std::endl;
    // Rationale: The defined operator is invoked; compliant.
    return 0;
}
