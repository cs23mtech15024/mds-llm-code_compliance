// Rule 2-10-4 Non-compliant: duplicate use of a class/union/enum name; MISRA requires a unique identifier project-wide.
#include <cstdio>
struct _sink { static void use(int) {} static void usef(float){} };
static int entry() { void a(){ union Cell{ int a; }; } void b(){ typedef int Cell; Cell z=1; _sink::use(z); } return 0; }
int main() { return entry(); }
