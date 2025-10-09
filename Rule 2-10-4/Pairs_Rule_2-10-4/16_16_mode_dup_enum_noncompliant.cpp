// Rule 2-10-4 Non-compliant: duplicate use of a class/union/enum name; must be unique across the project.
#include <cstdio>
struct Sink { static void i(int){} static void f(float){} };
static int entry() { void a(){ enum Mode{{ Off, On }}; Sink::i(0);} void b(){ enum Mode{{ Low, High }}; Sink::i(1);} return 0; }
int main() { return entry(); }
