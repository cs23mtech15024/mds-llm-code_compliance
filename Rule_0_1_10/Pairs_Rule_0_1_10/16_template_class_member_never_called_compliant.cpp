// Title: Template class member function is called (Compliant — Rule 0-1-10)
// Seed source: 16 (template class member) — corrected
#include <iostream>

template <typename T>
struct Accum {
    void clear() { size_ = 0; }
    void add(const T& t) { data_[size_++] = t; }
    T top() const { return data_[size_-1]; }
private:
    T data_[8];
    int size_;
};

int main() {
    Accum<int> a;
    a.add(7);
    a.clear();                 // call the previously unused member
    std::cout << a.top() << std::endl;
    // Rationale: All defined members are invoked at least once; compliant.
    return 0;
}
