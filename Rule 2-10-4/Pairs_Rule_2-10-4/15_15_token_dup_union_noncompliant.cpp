// Rule 2-10-4 Non-compliant: duplicate use of a class/union/enum name; must be unique across the project.
#include <cstdio>
struct Sink { static void i(int){} static void f(float){} };
static int entry() { void a(){ union Token{{ int a; }}; Sink::i(0);} void b(){ union Token{{ int b; }}; Sink::i(1);} return 0; }
int main() { return entry(); }
