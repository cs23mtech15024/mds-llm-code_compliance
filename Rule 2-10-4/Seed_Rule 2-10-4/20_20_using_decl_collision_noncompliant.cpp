// Rule 2-10-4 Non-compliant: duplicate use of a class/union/enum name; MISRA requires a unique identifier project-wide.
#include <cstdio>
struct _sink { static void use(int) {} static void usef(float){} };
static int entry() { namespace A{ struct Tag{}; } using A::Tag; void f(){ int Tag = 1; _sink::use(Tag); } return 0; }
int main() { return entry(); }
