// Rule 2-10-4 Compliant: class/union/enum name is unique across the project; renamed to eliminate duplication.
#include <cstdio>
struct _sink { static void use(int) {} static void usef(float){} };
static int entry() { void a(){ class Packet{ }; } int Packet_fn(){ return 1; } return Packet_fn(); }
int main() { return entry(); }
