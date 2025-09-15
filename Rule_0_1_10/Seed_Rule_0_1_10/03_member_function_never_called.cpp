// Seed (Non-compliant): Rule 0-1-10 — class member function defined but never called.
#include <iostream>

class Counter {
public:
    void reset() { value_ = 0; }       // defined, never called
    void inc()   { ++value_; }
    int  get() const { return value_; }
private:
    int value_;
};

int main() {
    Counter c;
    c.inc();
    std::cout << c.get() << "\n";
    return 0;
}
