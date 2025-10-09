// Rule 2-10-4 Compliant: type names are unique; duplicates removed by renaming.
#include <cstdio>
    struct Sink { static void i(int){} static void f(float){} };
    static int entry() { void a(){ enum Kind{{ A,B }}; }
namespace KindSpace {{ static int flag=7; }}
return KindSpace::flag; }
    int main() { return entry(); }
