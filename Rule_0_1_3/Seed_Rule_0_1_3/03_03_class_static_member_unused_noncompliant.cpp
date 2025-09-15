// Non-compliant: class static member declared/defined but never used.
struct Counter {
    static int instances; // unused
};

int Counter::instances = 0; // definition

int main() {
    return 0;
}
