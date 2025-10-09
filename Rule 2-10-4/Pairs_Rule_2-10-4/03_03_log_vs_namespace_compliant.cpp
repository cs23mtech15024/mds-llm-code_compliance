// Rule 2-10-4 Compliant: type names are unique; duplicates removed by renaming.
#include <cstdio>
    struct Sink { static void i(int){} static void f(float){} };
    static int entry() { void setup(){ class Log{ }; }
namespace LogNs {{ static int level=2; }}
return LogNs::level; }
    int main() { return entry(); }
