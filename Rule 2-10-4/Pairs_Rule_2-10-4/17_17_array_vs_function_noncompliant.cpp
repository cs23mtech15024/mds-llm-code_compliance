// Rule 2-10-4 Non-compliant: duplicate use of a class/union/enum name; must be unique across the project.
#include <cstdio>
struct Sink { static void i(int){} static void f(float){} };
static int entry() { template <class T> class Array{{ public: T v; }}; int Array(){{ return 4; }} Array<int> ar; (void)ar; return Array(); }
int main() { return entry(); }
