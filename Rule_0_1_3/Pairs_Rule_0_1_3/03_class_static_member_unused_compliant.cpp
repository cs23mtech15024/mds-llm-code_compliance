// Title: Class static data member used to control emission (Compliant per Rule 0-1-3)
// Seed example: 03_class_static_member_unused (from /mnt/data/Rule_0_1_3)
#include <iostream>

class Meter {
public:
    static int Enabled; // USED (0=off,1=on)
    void emit(const char* tag) const {
        if (Enabled) {
            std::cout << "[METER] " << tag << std::endl;
        }
    }
};

int Meter::Enabled = 1;

int main() {
    Meter m;
    m.emit("boot");
    // Rationale: The static member 'Enabled' gates output and is referenced; no declared variable
    // remains unused, so Rule 0-1-3 is satisfied.
    return 0;
}