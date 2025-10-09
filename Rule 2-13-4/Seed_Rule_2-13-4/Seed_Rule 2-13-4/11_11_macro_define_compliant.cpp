// Rule 2-13-4 Compliant: all literal suffixes are uppercase.
// Rationale: Uppercase suffixes ('U','L','F') avoid ambiguity per MISRA C++:2008 Rule 2-13-4.
#include <stddef.h>
    #include <wchar.h>
    static int entry() { #define MASK 0x1U
unsigned int m = MASK; return (int)m; }
    int main() { return entry(); }
