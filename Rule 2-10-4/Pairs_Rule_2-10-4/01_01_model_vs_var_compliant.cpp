// Rule 2-10-4 Compliant: type names are unique; duplicates removed by renaming.
#include <cstdio>
    struct Sink { static void i(int){} static void f(float){} };
    static int entry() { void maker(){ class Model{ public: int id; Model():id(0){} }; }
void run(){ int model_value = 77; Sink::i(model_value);} return 0; }
    int main() { return entry(); }
