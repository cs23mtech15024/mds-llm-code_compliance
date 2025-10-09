// Rule 2-13-4 Non-compliant: uses lowercase literal suffix(es); should be uppercase.
// Rationale: Lowercase suffixes (e.g., 'u','l','f') can be ambiguous; MISRA C++:2008 Rule 2-13-4 requires uppercase.
#include <stddef.h>
    #include <wchar.h>
    static int entry() { /* Use proper wide prefix 'L' for chars; numeric suffix fixed below */
unsigned long n = 4ul; wchar_t wc = L'A'; (void)wc; return (int)n; }
    int main() { return entry(); }
