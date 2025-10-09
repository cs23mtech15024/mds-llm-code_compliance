// Rule 2-10-4 Non-compliant: duplicate use of a class/union/enum name; MISRA requires a unique identifier project-wide.
#include <cstdio>
struct _sink { static void use(int) {} static void usef(float){} };
static int entry() { template <typename T> class Box{ public: T v; }; int Box(){ return 3; } Box<int> b; (void)b; return Box(); }
int main() { return entry(); }
