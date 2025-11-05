// Context: Image processing threshold parameter

// Seed 004 — C: function parameter without underscore prefix
#include <iostream>
void apply_threshold(int threshold, int value) { // C
    std::cout << "result=" << (value > threshold ? 255 : 0) << "\n";
}
int main(){
    apply_threshold(128, 200);
    return 0;
}