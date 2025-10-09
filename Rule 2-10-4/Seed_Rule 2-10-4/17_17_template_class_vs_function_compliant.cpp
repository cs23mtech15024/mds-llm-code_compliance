// Rule 2-10-4 Compliant: class/union/enum name is unique across the project; renamed to eliminate duplication.
#include <cstdio>
struct _sink { static void use(int) {} static void usef(float){} };
static int entry() { template <typename T> class Box{ public: T v; }; int MakeBox(){ return 3; } Box<int> b; (void)b; return MakeBox(); }
int main() { return entry(); }
