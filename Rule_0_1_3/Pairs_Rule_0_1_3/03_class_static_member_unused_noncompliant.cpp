// Title: Class static data member declared but never referenced (Non-compliant per Rule 0-1-3)
// Seed example: 03_class_static_member_unused (from /mnt/data/Rule_0_1_3)
#include <iostream>

class Meter {
public:
    static int Enabled; // UNUSED (violates Rule 0-1-3)
    void emit(const char* tag) const {
        std::cout << "[METER] " << tag << std::endl;
    }
};

int Meter::Enabled = 0;

int main() {
    Meter m;
    m.emit("boot");
    // Rationale: 'Meter::Enabled' exists but is never read or written anywhere; unused variable
    // breaks Rule 0-1-3.
    return 0;
}