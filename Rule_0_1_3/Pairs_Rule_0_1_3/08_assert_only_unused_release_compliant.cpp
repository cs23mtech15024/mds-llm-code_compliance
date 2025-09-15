// Title: Variable is used in both debug and release (Compliant per Rule 0-1-3)
// Seed example: 08_assert_release_unused (from /mnt/data/Rule_0_1_3)
#include <iostream>
#include <cassert>

static int calc() { return 42; }

int main() {
#ifndef NDEBUG
    int res = calc();
    assert(res == 42);
    std::cout << "dbg=" << res << std::endl;
#else
    std::cout << "rel=" << calc() << std::endl;
#endif
    // Rationale: No configuration leaves a declared variable unused — compliant.
    return 0;
}