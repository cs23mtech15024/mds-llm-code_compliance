// Rule 2-10-4 Compliant: type names are unique; duplicates removed by renaming.
#include <cstdio>
    struct Sink { static void i(int){} static void f(float){} };
    static int entry() { void c1(){ enum Color{{ Red, Green }}; }
void c2(){ typedef unsigned Color_u; Color_u m=2; Sink::i((int)m);} return 0; }
    int main() { return entry(); }
