// Rule 2-10-4 Non-compliant: duplicate use of a class/union/enum name; must be unique across the project.
#include <cstdio>
struct Sink { static void i(int){} static void f(float){} };
static int entry() { void pre(){ class Pipe; } void use(){ int Pipe=11; Sink::i(Pipe);} return 0; }
int main() { return entry(); }
