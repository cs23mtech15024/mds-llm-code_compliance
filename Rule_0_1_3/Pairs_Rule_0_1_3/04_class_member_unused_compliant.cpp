// Title: All struct members are meaningfully referenced (Compliant per Rule 0-1-3)
// Seed example: 04_class_member_unused (from /mnt/data/Rule_0_1_3)
#include <iostream>
#include <string>

struct Record {
    int id;
    int padding;
    std::string name;
    Record(int i, const std::string& n) : id(i), padding(0), name(n) {}
    int total() const { return id + padding + static_cast<int>(name.size()); }
};

static void print(const Record& r) {
    std::cout << "total=" << r.total() << std::endl;
}

int main() {
    Record r(101, "alpha");
    r.padding = 5; // USE the member
    print(r);
    // Rationale: 'padding' participates in computation; no unused variables remain, compliant
    // with Rule 0-1-3.
    return 0;
}