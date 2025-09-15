// Seed (Non-compliant): Rule 0-1-10 — internal-linkage static function never called.
#include <iostream>

static void internal_step() {          // defined, never called
    std::cout << "step\n";
}

int main() {
    std::cout << "run\n";
    return 0;
}
