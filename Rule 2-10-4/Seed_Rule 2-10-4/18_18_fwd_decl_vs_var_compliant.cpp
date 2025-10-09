// Rule 2-10-4 Compliant: class/union/enum name is unique across the project; renamed to eliminate duplication.
#include <cstdio>
struct _sink { static void use(int) {} static void usef(float){} };
static int entry() { void a(){ class Port; } void b(){ int port_num = 9; _sink::use(port_num); } return 0; }
int main() { return entry(); }
