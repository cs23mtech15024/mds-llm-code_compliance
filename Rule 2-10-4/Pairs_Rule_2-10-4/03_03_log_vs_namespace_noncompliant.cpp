// Rule 2-10-4 Non-compliant: duplicate use of a class/union/enum name; must be unique across the project.
#include <cstdio>
    struct Sink { static void i(int){} static void f(float){} };
    static int entry() { void setup(){ class Log{ }; }
namespace Log {{ static int level=2; }}
return Log::level; }
    int main() { return entry(); }
