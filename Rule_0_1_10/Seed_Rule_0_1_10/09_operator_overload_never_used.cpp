// Seed (Non-compliant): Rule 0-1-10 — operator overload defined but never used.
#include <iostream>

struct Vec {
    int x, y;
};

Vec operator+(const Vec& a, const Vec& b) { // defined, never used
    Vec r; r.x = a.x + b.x; r.y = a.y + b.y; return r;
}

int main() {
    Vec a = {1,2};
    Vec b = {3,4};
    (void)a; (void)b;
    std::cout << "ready\n";
    return 0;
}
