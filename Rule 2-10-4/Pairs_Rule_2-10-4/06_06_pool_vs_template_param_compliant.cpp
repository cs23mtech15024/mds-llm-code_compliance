// Rule 2-10-4 Compliant: type names are unique; duplicates removed by renaming.
#include <cstdio>
    struct Sink { static void i(int){} static void f(float){} };
    static int entry() { void pre(){ class Pool{{}}; }
template <typename PoolT> struct Box{{ PoolT v; }}; Box<int> bx; (void)bx; return 0; }
    int main() { return entry(); }
