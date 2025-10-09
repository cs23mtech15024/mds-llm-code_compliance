// Rule 2-10-4 Non-compliant: duplicate use of a class/union/enum name; MISRA requires a unique identifier project-wide.
#include <cstdio>
struct _sink { static void use(int) {} static void usef(float){} };
static int entry() { void a(){ class Frame{ public: int w; }; } void b(){ typedef int Frame; Frame x = 3; _sink::use(x); } return 0; }
int main() { return entry(); }
