// Rule 2-10-4 Compliant: type names are unique; duplicates removed by renaming.
#include <cstdio>
struct Sink { static void i(int){} static void f(float){} };
static int entry() { void pre(){ class Pipe; } void use(){ int pipe_num=11; Sink::i(pipe_num);} return 0; }
int main() { return entry(); }
