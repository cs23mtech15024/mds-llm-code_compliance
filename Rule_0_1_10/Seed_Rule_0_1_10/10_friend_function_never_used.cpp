// Seed (Non-compliant): Rule 0-1-10 — friend function defined but never called.
#include <iostream>

class Box {
    int v;
public:
    Box(int w): v(w) {}
    friend int volume(const Box& b) {  // defined, never called
        return b.v;
    }
};

int main() {
    Box b(10);
    std::cout << "box\n";
    return 0;
}
