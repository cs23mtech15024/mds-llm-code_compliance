// Context: Saturation limit enforcer

// Seed 049 — C: function without underscore prefix
#include <iostream>
int saturate(int value, int limit) { // C
    return value > limit ? limit : value;
}
int main(){
    std::cout << "result=" << saturate(150, 100) << "\n";
    return 0;
}