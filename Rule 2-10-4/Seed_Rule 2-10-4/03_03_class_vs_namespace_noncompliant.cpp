// Rule 2-10-4 Non-compliant: duplicate use of a class/union/enum name; MISRA requires a unique identifier project-wide.
#include <cstdio>
struct _sink { static void use(int) {} static void usef(float){} };
static int entry() { void x(){ class Stream{ }; } namespace Stream { static int id=0; } return Stream::id; }
int main() { return entry(); }
