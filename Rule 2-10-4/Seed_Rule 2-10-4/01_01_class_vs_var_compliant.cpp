// Rule 2-10-4 Compliant: class/union/enum name is unique across the project; renamed to eliminate duplication.
#include <cstdio>
struct _sink { static void use(int) {} static void usef(float){} };
static int entry() { void f1(){ class Speed { public: int v; Speed():v(0){} }; _sink::use(0); } void f2(){ int speed_val = 42; _sink::use(speed_val); } return 0; }
int main() { return entry(); }
