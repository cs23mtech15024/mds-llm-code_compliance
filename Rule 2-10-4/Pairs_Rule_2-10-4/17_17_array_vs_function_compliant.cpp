// Rule 2-10-4 Compliant: type names are unique; duplicates removed by renaming.
#include <cstdio>
struct Sink { static void i(int){} static void f(float){} };
static int entry() { template <class T> class Array{{ public: T v; }}; int makeArray(){{ return 4; }} Array<int> ar; (void)ar; return makeArray(); }
int main() { return entry(); }
