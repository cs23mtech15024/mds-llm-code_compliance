// Rule 2-10-4 Non-compliant: duplicate use of a class/union/enum name; MISRA requires a unique identifier project-wide.
#include <cstdio>
struct _sink { static void use(int) {} static void usef(float){} };
static int entry() { void a(){ enum Status{ OK=0, FAIL=1 }; } void b(){ int Status = 0; _sink::use(Status); } return 0; }
int main() { return entry(); }
