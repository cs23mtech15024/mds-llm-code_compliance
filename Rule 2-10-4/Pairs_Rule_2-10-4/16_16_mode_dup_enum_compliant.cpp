// Rule 2-10-4 Compliant: type names are unique; duplicates removed by renaming.
#include <cstdio>
struct Sink { static void i(int){} static void f(float){} };
static int entry() { void a(){ enum Mode{{ Off, On }}; Sink::i(0);} void b(){ enum Mode2{{ Low, High }}; Sink::i(1);} return 0; }
int main() { return entry(); }
