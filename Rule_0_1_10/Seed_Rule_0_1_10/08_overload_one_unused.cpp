// Seed (Non-compliant): Rule 0-1-10 — one overload is never called.
#include <iostream>

void print(int)   { std::cout << "int\n"; }
void print(char)  { std::cout << "char\n"; }  // defined, never called
void print(const char*) { std::cout << "cstr\n"; }

int main() {
    print(42);
    print("hi");
    return 0;
}
