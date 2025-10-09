// Rule 2-10-4 Compliant: type names are unique; duplicates removed by renaming.
#include <cstdio>
struct Sink { static void i(int){} static void f(float){} };
static int entry() { void a(){ union Token{{ int a; }}; Sink::i(0);} void b(){ union TokenX{{ int b; }}; Sink::i(1);} return 0; }
int main() { return entry(); }
