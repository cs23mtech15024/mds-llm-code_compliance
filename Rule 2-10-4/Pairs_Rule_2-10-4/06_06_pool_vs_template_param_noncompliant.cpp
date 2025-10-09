// Rule 2-10-4 Non-compliant: duplicate use of a class/union/enum name; must be unique across the project.
#include <cstdio>
    struct Sink { static void i(int){} static void f(float){} };
    static int entry() { void pre(){ class Pool{{}}; }
template <typename Pool> struct Box{{ Pool v; }}; Box<int> bx; (void)bx; return 0; }
    int main() { return entry(); }
