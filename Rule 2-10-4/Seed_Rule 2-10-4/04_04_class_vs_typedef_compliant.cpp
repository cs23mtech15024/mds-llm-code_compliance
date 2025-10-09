// Rule 2-10-4 Compliant: class/union/enum name is unique across the project; renamed to eliminate duplication.
#include <cstdio>
struct _sink { static void use(int) {} static void usef(float){} };
static int entry() { void a(){ class Frame{ public: int w; }; } void b(){ typedef int Frame_t; Frame_t x = 3; _sink::use(x); } return 0; }
int main() { return entry(); }
