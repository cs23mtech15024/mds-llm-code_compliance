// Title: Namespace-scope variable never referenced (Non-compliant per Rule 0-1-3)
// Seed example: 01_global_unused (from /mnt/data/Rule_0_1_3)
#include <iostream>
#include <string>

// Simulated config value at namespace scope that is never referenced.
int g_verbose_level = 3; // UNUSED (violates Rule 0-1-3)

static void print_header(const std::string& title) {
    std::cout << "=== " << title << " ===" << std::endl;
}

static void dump_items() {
    for (int i = 0; i < 5; ++i) {
        std::cout << "Item#" << i << " ok" << std::endl;
    }
}

int main() {
    print_header("Daily Report");
    dump_items();
    // Rationale: The global 'g_verbose_level' is declared but never referenced; this is noise and
    // may conceal logic mistakes, violating MISRA C++:2008 Rule 0-1-3 (unused variables).
    return 0;
}