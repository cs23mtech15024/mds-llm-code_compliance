// Rule 2-10-4 Non-compliant: duplicate use of a class/union/enum name; must be unique across the project.
#include <cstdio>
    struct Sink { static void i(int){} static void f(float){} };
    static int entry() { void maker(){ class Model{ public: int id; Model():id(0){} }; }
void run(){ int Model = 77; Sink::i(Model);} return 0; }
    int main() { return entry(); }
