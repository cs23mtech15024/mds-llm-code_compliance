// Title: Member function defined but never called (Non-compliant — Rule 0-1-10)
// Seed source: 02_placeholder_never_called.cpp
#include <iostream>

class Session {
public:
    void open()  { std::cout << "open\n"; }
    void flush() { std::cout << "flush\n"; } // defined, NEVER called
    void close() { std::cout << "close\n"; }
};

int main() {
    Session s;
    s.open();
    s.close();
    // Rationale: 'flush' is never invoked; defined member function unused -> non-compliant.
    return 0;
}
