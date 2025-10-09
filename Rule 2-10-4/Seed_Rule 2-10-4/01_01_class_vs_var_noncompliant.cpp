// Rule 2-10-4 Non-compliant: duplicate use of a class/union/enum name; MISRA requires a unique identifier project-wide.
#include <cstdio>
struct _sink { static void use(int) {} static void usef(float){} };
static int entry() { void f1(){ class Speed { public: int v; Speed():v(0){} }; _sink::use(0); } void f2(){ int Speed = 42; _sink::use(Speed); } return 0; }
int main() { return entry(); }
