// Rule 2-10-4 Compliant: class/union/enum name is unique across the project; renamed to eliminate duplication.
#include <cstdio>
struct _sink { static void use(int) {} static void usef(float){} };
static int entry() { struct Outer{ enum State{ Idle, Busy }; }; int outer_state_val = 0; _sink::use(outer_state_val); return 0; }
int main() { return entry(); }
