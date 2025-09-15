// Title: Namespace-scope variable is used to control output (Compliant per Rule 0-1-3)
// Seed example: 01_global_unused (from /mnt/data/Rule_0_1_3)
#include <iostream>
#include <string>

// Used meaningfully to gate verbosity.
int g_verbose_level = 3; // USED

static void print_header(const std::string& title) {
    if (g_verbose_level >= 1) {
        std::cout << "=== " << title << " ===" << std::endl;
    }
}

static void dump_items() {
    for (int i = 0; i < 5; ++i) {
        if (g_verbose_level >= 2) {
            std::cout << "Item#" << i << " ok" << std::endl;
        }
    }
}

int main() {
    print_header("Daily Report");
    dump_items();
    // Rationale: All declared variables are referenced; 'g_verbose_level' influences behavior,
    // so no variable remains unused — compliant with Rule 0-1-3.
    return 0;
}