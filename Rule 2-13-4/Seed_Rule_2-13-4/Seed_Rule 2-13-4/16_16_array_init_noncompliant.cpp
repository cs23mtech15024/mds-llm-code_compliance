// Rule 2-13-4 Non-compliant: uses lowercase literal suffix(es); should be uppercase.
// Rationale: Lowercase suffixes (e.g., 'u','l','f') can be ambiguous; MISRA C++:2008 Rule 2-13-4 requires uppercase.
#include <stddef.h>
#include <wchar.h>
static int entry() { unsigned long a[3] = {1ul, 2ul, 3ul}; return (int)a[2]; }
int main() { return entry(); }
