// Context: Range boundary checker

// Seed 037 — C: function and parameters without underscore prefix
#include <iostream>
bool in_range(int val, int min, int max) { // C
    return val >= min && val <= max;
}
int main(){
    std::cout << "valid=" << in_range(50, 0, 100) << "\n";
    return 0;
}