// Context: Array size calculation helper

// Seed 009 — C: function without underscore prefix
#include <iostream>
int get_array_size(int count) { // C
    return count * sizeof(int);
}
int main(){
    std::cout << "size=" << get_array_size(10) << "\n";
    return 0;
}