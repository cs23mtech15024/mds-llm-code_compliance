// Context: Range boundary checker

// Seed 037 — NC: function and parameters start with underscore
#include <iostream>
bool _in_range(int _val, int _min, int _max) { // NC
    return _val >= _min && _val <= _max;
}
int main(){
    std::cout << "valid=" << _in_range(50, 0, 100) << "\n";
    return 0;
}