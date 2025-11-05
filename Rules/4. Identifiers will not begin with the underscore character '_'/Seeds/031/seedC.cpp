// Context: Frame counter incrementer

// Seed 031 — C: function without underscore prefix
#include <iostream>
void increment_frame(int& count) { // C
    count++;
}
int main(){
    int frames = 0;
    increment_frame(frames);
    std::cout << "frames=" << frames << "\n";
    return 0;
}