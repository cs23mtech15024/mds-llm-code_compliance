// Context: Image processing threshold parameter

// Seed 004 — NC: function parameter starts with underscore
#include <iostream>
void apply_threshold(int _threshold, int value) { // NC
    std::cout << "result=" << (value > _threshold ? 255 : 0) << "\n";
}
int main(){
    apply_threshold(128, 200);
    return 0;
}