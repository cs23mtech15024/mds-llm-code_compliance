// ------ Compliant
// Seed: Non-compliant header: int lookupTable[3] = {1,2,3};   // Compliant header: extern int lookupTable[3];
// Context: Header now holds only declarations; definitions moved into implementation.
// Source: MISRA C++ 2008 Rule 8-5-2 ("A header file shall contain only declarations and macros").
// Compliance: Header region contains only declarations; definitions appear in implementation file.

#include <iostream>
#include <numeric>
#include <vector>

// ------------------- good_header.h (inlined for demo) -------------------
// COMPLIANT: header contains only declarations
//
// Seed (header declaration): extern int lookupTable[3];
extern int lookupTable[3]; // declaration only
int getValue(int index);   // prototype only
// -----------------------------------------------------------------------

// Implementation section (compliant)
int lookupTable[3] = {1, 2, 3}; // COMPLIANT: definition in implementation file

int getValue(int index) {
    if (index < 0 || index >= 3) return -1;
    return lookupTable[index];
}

int main() {
    int sum = 0;
    for (int i = 0; i < 3; ++i) {
        int v = getValue(i);
        sum += v;
        std::cout << "[C] lookupTable[" << i << "]=" << v << '\n';
    }
    std::cout << "[C] total=" << sum << '\n';
    return 0;
}