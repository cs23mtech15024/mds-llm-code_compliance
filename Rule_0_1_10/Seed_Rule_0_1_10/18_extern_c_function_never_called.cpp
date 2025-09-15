// Seed (Non-compliant): Rule 0-1-10 — extern "C" function defined but never called.
#include <iostream>

extern "C" void c_api_do() {           // defined, never called
    std::cout << "c_api\n";
}

int main() {
    std::cout << "host\n";
    return 0;
}
