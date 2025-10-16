// ------ Non-Compliant
// Seed: Non-compliant header: int lookupTable[3] = {1,2,3};   // Compliant header: extern int lookupTable[3];
// Context: Header defines a non-const global array and a helper function — both are definitions, not declarations.
// Source: MISRA C++ 2008 Rule 8-5-2 ("A header file shall contain only declarations and macros").
// Violation: Header contains a non-const variable definition and a non-inline function definition.

#include <iostream>
#include <numeric>
#include <vector>

// ------------------- bad_header.h (inlined for demo) -------------------
// NON-COMPLIANT: header contains definitions (violates 8-5-2)
//
// Seed (must appear in header): int lookupTable[3] = {1,2,3};
int lookupTable[3] = {1, 2, 3}; // NON-COMPLIANT: non-const variable defined in header

int getValue(int index) { // NON-COMPLIANT: non-inline function defined in header
    if (index < 0 || index >= 3) return -1;
    return lookupTable[index];
}
// ----------------------------------------------------------------------

int main() {
    int sum = 0;
    for (int i = 0; i < 3; ++i) {
        int v = getValue(i);
        sum += v;
        std::cout << "[NC] lookupTable[" << i << "]=" << v << '\n';
    }
    std::cout << "[NC] total=" << sum << '\n';
    return 0;
}