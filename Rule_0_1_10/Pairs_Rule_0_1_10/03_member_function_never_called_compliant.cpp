// Title: Member function is called once (Compliant — Rule 0-1-10)
// Seed source: 03 (member function) — corrected
#include <iostream>

class Session {
public:
    void open()  { std::cout << "open\n"; }
    void flush() { std::cout << "flush\n"; } // now USED
    void close() { std::cout << "close\n"; }
};

int main() {
    Session s;
    s.open();
    s.flush(); // actual call
    s.close();
    // Rationale: All defined member functions are invoked at least once; compliant.
    return 0;
}
