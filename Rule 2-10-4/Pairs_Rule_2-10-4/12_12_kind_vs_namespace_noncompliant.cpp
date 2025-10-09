// Rule 2-10-4 Non-compliant: duplicate use of a class/union/enum name; must be unique across the project.
#include <cstdio>
    struct Sink { static void i(int){} static void f(float){} };
    static int entry() { void a(){ enum Kind{{ A,B }}; }
namespace Kind {{ static int flag=7; }}
return Kind::flag; }
    int main() { return entry(); }
