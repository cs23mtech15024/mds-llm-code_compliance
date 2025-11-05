// Context: Error code validator

// Seed 034 — NC: function starts with underscore
#include <iostream>
bool _is_error(int code) { // NC
    return code < 0;
}
int main(){
    std::cout << "error=" << _is_error(-1) << "\n";
    return 0;
}