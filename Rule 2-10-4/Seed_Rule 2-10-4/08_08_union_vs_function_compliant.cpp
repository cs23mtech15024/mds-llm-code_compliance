// Rule 2-10-4 Compliant: class/union/enum name is unique across the project; renamed to eliminate duplication.
#include <cstdio>
struct _sink { static void use(int) {} static void usef(float){} };
static int entry() { void f(){ union Event{ int a; }; } int Event_fn(){ return 2; } return Event_fn(); }
int main() { return entry(); }
