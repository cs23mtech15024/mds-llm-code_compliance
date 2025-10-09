// Rule 2-10-4 Compliant: type names are unique; duplicates removed by renaming.
#include <cstdio>
    struct Sink { static void i(int){} static void f(float){} };
    static int entry() { void p(){ class Frame{ public: int w; }; }
void q(){ typedef int Frame_t; Frame_t w=10; Sink::i(w);} return 0; }
    int main() { return entry(); }
