// Title: Struct has a member that is never referenced (Non-compliant per Rule 0-1-3)
// Seed example: 04_class_member_unused (from /mnt/data/Rule_0_1_3)
#include <iostream>
#include <string>

struct Record {
    int id;
    int padding; // UNUSED (violates Rule 0-1-3)
    std::string name;
    Record(int i, const std::string& n) : id(i), padding(0), name(n) {}
};

static void print(const Record& r) {
    std::cout << "id=" << r.id << " name=" << r.name << std::endl;
}

int main() {
    Record r(101, "alpha");
    print(r);
    // Rationale: 'padding' is declared but never read/written anywhere; unused member violates
    // Rule 0-1-3.
    return 0;
}