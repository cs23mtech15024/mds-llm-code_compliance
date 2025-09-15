// Non-compliant: variable used only in assert() becomes unused when NDEBUG is defined.
#include <cassert>

int compute() { return 42; }

int main() {
    int result = compute();   // unused in release builds
    assert(result == 42);
    return 0;
}
