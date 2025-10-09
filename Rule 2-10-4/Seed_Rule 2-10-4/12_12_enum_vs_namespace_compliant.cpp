// Rule 2-10-4 Compliant: class/union/enum name is unique across the project; renamed to eliminate duplication.
#include <cstdio>
struct _sink { static void use(int) {} static void usef(float){} };
static int entry() { void a(){ enum Level{ Low=0, High=1 }; } namespace Severity { static int x=5; } return Severity::x; }
int main() { return entry(); }
