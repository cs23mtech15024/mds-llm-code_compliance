// Rule 2-10-4 Non-compliant: duplicate use of a class/union/enum name; MISRA requires a unique identifier project-wide.
#include <cstdio>
struct _sink { static void use(int) {} static void usef(float){} };
static int entry() { void a(){ enum Level{ Low=0, High=1 }; } namespace Level { static int x=5; } return Level::x; }
int main() { return entry(); }
