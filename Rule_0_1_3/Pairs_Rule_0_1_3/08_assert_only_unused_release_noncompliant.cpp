// Title: Variable used only in assert -> unused in NDEBUG (Non-compliant per Rule 0-1-3)
// Seed example: 08_assert_release_unused (from /mnt/data/Rule_0_1_3)
#include <iostream>
#include <cassert>

static int calc() { return 42; }

int main() {
    int res = calc(); // ONLY used by assert -> may be UNUSED in release
    assert(res == 42);
    std::cout << "ok" << std::endl;
    // Rationale: With NDEBUG, 'res' becomes an unused variable; violates Rule 0-1-3.
    return 0;
}