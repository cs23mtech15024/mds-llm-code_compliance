// Title: Template class member function defined but never called (Non-compliant — Rule 0-1-10)
// Seed source: 08_placeholder_never_called.cpp
#include <iostream>

template <typename T>
struct Accum {
    void clear() { size_ = 0; } // defined, NEVER called
    void add(const T& t) { data_[size_++] = t; }
    T top() const { return data_[size_-1]; }
private:
    T data_[8];
    int size_;
};

int main() {
    Accum<int> a;
    a.add(7);
    std::cout << a.top() << std::endl;
    // Rationale: clear() is never invoked; non-compliant.
    return 0;
}
