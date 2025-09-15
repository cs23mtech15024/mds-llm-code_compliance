// Compliant: remove the unused member or use it meaningfully.
#include <iostream>
struct Packet {
    int id;
    int padding;
    Packet(int i): id(i), padding(0) {}
    int total() const { return id + padding; }
};

int main() {
    Packet p(7);
    std::cout << p.total() << '\n';
    return 0;
}
