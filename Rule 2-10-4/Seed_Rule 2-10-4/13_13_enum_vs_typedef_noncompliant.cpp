// Rule 2-10-4 Non-compliant: duplicate use of a class/union/enum name; MISRA requires a unique identifier project-wide.
#include <cstdio>
struct _sink { static void use(int) {} static void usef(float){} };
static int entry() { void a(){ enum Channel{ A=0,B=1 }; } void b(){ typedef int Channel; Channel c=1; _sink::use(c); } return 0; }
int main() { return entry(); }
