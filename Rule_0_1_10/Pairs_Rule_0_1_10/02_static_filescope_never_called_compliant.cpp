// Title: File-scope static function is called (Compliant — Rule 0-1-10)
// Seed source: 02 (file-scope static) — corrected
#include <iostream>

static void internal_probe() { std::cout << "probe\n"; }

int main() {
    internal_probe(); // actual call
    std::cout << "init" << std::endl;
    // Rationale: internal_probe is defined and invoked; compliant with Rule 0-1-10.
    return 0;
}
