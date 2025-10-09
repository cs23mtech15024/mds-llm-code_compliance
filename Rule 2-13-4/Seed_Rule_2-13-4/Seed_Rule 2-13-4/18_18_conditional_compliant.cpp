// Rule 2-13-4 Compliant: all literal suffixes are uppercase.
// Rationale: Uppercase suffixes ('U','L','F') avoid ambiguity per MISRA C++:2008 Rule 2-13-4.
#include <stddef.h>
#include <wchar.h>
static int entry() { unsigned int t = 3U; unsigned int r = (t ? 10U : 0U); return (int)r; }
int main() { return entry(); }
