// Rule 2-10-4 Non-compliant: duplicate use of a class/union/enum name; MISRA requires a unique identifier project-wide.
#include <cstdio>
struct _sink { static void use(int) {} static void usef(float){} };
static int entry() { void f(){ union Payload{ int a; float b; }; } void g(){ int Payload = 7; _sink::use(Payload); } return 0; }
int main() { return entry(); }
