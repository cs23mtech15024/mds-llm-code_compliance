// Rule 2-10-4 Non-compliant: duplicate use of a class/union/enum name; must be unique across the project.
#include <cstdio>
    struct Sink { static void i(int){} static void f(float){} };
    static int entry() { void c1(){ enum Color{{ Red, Green }}; }
void c2(){ typedef unsigned Color; Color m=2; Sink::i((int)m);} return 0; }
    int main() { return entry(); }
