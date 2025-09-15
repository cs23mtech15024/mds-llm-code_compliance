// Seed (Non-compliant): Rule 0-1-10 — free function is defined but never called.
#include <iostream>

void log_start() {
    std::cout << "start\n";
}

void helper_unused() {                 // defined, never called
    std::cout << "helper\n";
}

int main() {
    log_start();
    std::cout << "work\n";
    return 0;
}
