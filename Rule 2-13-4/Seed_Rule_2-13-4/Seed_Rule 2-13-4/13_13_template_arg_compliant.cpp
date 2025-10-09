// Rule 2-13-4 Compliant: all literal suffixes are uppercase.
// Rationale: Uppercase suffixes ('U','L','F') avoid ambiguity per MISRA C++:2008 Rule 2-13-4.
#include <stddef.h>
    #include <wchar.h>
    static int entry() { template<int N> struct S { enum { v = N }; };
int x = S<0x10U>::v; return x; }
    int main() { return entry(); }
