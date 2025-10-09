// Rule 2-10-4 Non-compliant: duplicate use of a class/union/enum name; must be unique across the project.
#include <cstdio>
    struct Sink { static void i(int){} static void f(float){} };
    static int entry() { void p(){ class Frame{ public: int w; }; }
void q(){ typedef int Frame; Frame w=10; Sink::i(w);} return 0; }
    int main() { return entry(); }
