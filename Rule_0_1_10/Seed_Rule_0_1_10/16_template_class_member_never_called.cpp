// Seed (Non-compliant): Rule 0-1-10 — template class member defined but never called.
#include <iostream>

template <typename T>
struct Stack {
    void clear() { size_ = 0; }        // defined, never called
    void push(const T& t) { data_[size_++] = t; }
    T top() const { return data_[size_-1]; }
private:
    T data_[8];
    int size_;
};

int main() {
    Stack<int> s;
    s.push(3);
    std::cout << s.top() << "\n";
    return 0;
}
