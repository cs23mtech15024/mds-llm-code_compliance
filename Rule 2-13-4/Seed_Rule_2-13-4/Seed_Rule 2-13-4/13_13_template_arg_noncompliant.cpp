// Rule 2-13-4 Non-compliant: uses lowercase literal suffix(es); should be uppercase.
// Rationale: Lowercase suffixes (e.g., 'u','l','f') can be ambiguous; MISRA C++:2008 Rule 2-13-4 requires uppercase.
#include <stddef.h>
    #include <wchar.h>
    static int entry() { template<int N> struct S { enum { v = N }; };
int x = S<0x10u>::v; return x; }
    int main() { return entry(); }
