// Rule 2-10-4 Non-compliant: duplicate use of a class/union/enum name; MISRA requires a unique identifier project-wide.
#include <cstdio>
struct _sink { static void use(int) {} static void usef(float){} };
static int entry() { void f(){ union Event{ int a; }; } int Event(){ return 2; } return Event(); }
int main() { return entry(); }
