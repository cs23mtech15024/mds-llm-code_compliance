// Rule 2-10-4 Non-compliant: duplicate use of a class/union/enum name; MISRA requires a unique identifier project-wide.
#include <cstdio>
struct _sink { static void use(int) {} static void usef(float){} };
static int entry() { void f(){ enum Phase{ P0, P1 }; _sink::use(0);} void g(){ enum Phase{ Q0, Q1 }; _sink::use(1);} return 0; }
int main() { return entry(); }
