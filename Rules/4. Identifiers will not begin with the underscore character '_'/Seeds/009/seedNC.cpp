// Context: Array size calculation helper

// Seed 009 — NC: function starts with underscore
#include <iostream>
int _get_array_size(int count) { // NC
    return count * sizeof(int);
}
int main(){
    std::cout << "size=" << _get_array_size(10) << "\n";
    return 0;
}