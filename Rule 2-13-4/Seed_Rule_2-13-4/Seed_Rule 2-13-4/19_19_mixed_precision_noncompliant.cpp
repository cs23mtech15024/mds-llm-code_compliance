// Rule 2-13-4 Non-compliant: uses lowercase literal suffix(es); should be uppercase.
// Rationale: Lowercase suffixes (e.g., 'u','l','f') can be ambiguous; MISRA C++:2008 Rule 2-13-4 requires uppercase.
#include <stddef.h>
#include <wchar.h>
static int entry() { float sf = 2.0f; long double ld = 1.0l; return (int)(sf + (float)ld); }
int main() { return entry(); }
