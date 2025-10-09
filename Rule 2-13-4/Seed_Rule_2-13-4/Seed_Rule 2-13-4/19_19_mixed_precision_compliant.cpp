// Rule 2-13-4 Compliant: all literal suffixes are uppercase.
// Rationale: Uppercase suffixes ('U','L','F') avoid ambiguity per MISRA C++:2008 Rule 2-13-4.
#include <stddef.h>
#include <wchar.h>
static int entry() { float sf = 2.0F; long double ld = 1.0L; return (int)(sf + (float)ld); }
int main() { return entry(); }
