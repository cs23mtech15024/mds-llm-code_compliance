// Context: Saturation limit enforcer

// Seed 049 — NC: function starts with underscore
#include <iostream>
int _saturate(int value, int limit) { // NC
    return value > limit ? limit : value;
}
int main(){
    std::cout << "result=" << _saturate(150, 100) << "\n";
    return 0;
}