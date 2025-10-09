// Rule 2-10-4 Compliant: type names are unique; duplicates removed by renaming.
#include <cstdio>
struct Sink { static void i(int){} static void f(float){} };
static int entry() { void a(){ class Window{{}}; Sink::i(0);} void b(){ class Window2{{}}; Sink::i(1);} return 0; }
int main() { return entry(); }
