// Rule 2-10-4 Non-compliant: duplicate use of a class/union/enum name; MISRA requires a unique identifier project-wide.
#include <cstdio>
struct _sink { static void use(int) {} static void usef(float){} };
static int entry() { void a(){ enum Mode{ Read=0, Write=1 }; } int Mode(){ return 0; } return Mode(); }
int main() { return entry(); }
