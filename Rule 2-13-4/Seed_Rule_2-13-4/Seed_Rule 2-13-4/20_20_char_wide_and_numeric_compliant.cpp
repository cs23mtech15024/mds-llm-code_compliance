// Rule 2-13-4 Compliant: all literal suffixes are uppercase.
// Rationale: Uppercase suffixes ('U','L','F') avoid ambiguity per MISRA C++:2008 Rule 2-13-4.
#include <stddef.h>
    #include <wchar.h>
    static int entry() { /* Use proper wide prefix 'L' for chars; numeric suffix fixed below */
unsigned long n = 4UL; wchar_t wc = L'A'; (void)wc; return (int)n; }
    int main() { return entry(); }
