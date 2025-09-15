// Non-compliant: data member declared but never used anywhere.
struct Packet {
    int id;
    int padding; // unused member (never read or written)
    Packet(int i): id(i), padding(0) {}
};

int main() {
    Packet p(7);
    // 'padding' is never referenced in the project.
    (void)p.id; // simulate use of id to avoid other warnings
    return 0;
}
