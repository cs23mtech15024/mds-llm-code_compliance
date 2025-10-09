// Rule 2-13-4 Compliant: all literal suffixes are uppercase.
// Rationale: Uppercase suffixes ('U','L','F') avoid ambiguity per MISRA C++:2008 Rule 2-13-4.
#include <stddef.h>
#include <wchar.h>
static int entry() { unsigned long a[3] = {1UL, 2UL, 3UL}; return (int)a[2]; }
int main() { return entry(); }
