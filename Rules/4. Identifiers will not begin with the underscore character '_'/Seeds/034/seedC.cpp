// Context: Error code validator

// Seed 034 — C: function without underscore prefix
#include <iostream>
bool is_error(int code) { // C
    return code < 0;
}
int main(){
    std::cout << "error=" << is_error(-1) << "\n";
    return 0;
}