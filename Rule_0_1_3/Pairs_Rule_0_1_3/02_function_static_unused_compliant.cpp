// Title: Function-scope static variable used to retain state (Compliant per Rule 0-1-3)
// Seed example: 02_local_static_unused (from /mnt/data/Rule_0_1_3)
#include <iostream>

static int step_and_get() {
    static int s_counter = 0; // USED (retains state across calls)
    ++s_counter;
    return s_counter;
}

int main() {
    for (int i = 0; i < 10; ++i) {
        int now = step_and_get();
        if ((now % 5) == 0) {
            std::cout << "|";
        } else {
            std::cout << ".";
        }
    }
    std::cout << std::endl;
    // Rationale: All declared variables are referenced; static 's_counter' is used to track calls,
    // hence compliant with Rule 0-1-3.
    return 0;
}