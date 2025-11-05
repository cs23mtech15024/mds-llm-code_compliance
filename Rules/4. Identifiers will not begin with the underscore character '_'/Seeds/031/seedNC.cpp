// Context: Frame counter incrementer

// Seed 031 — NC: function starts with underscore
#include <iostream>
void _increment_frame(int& count) { // NC
    count++;
}
int main(){
    int frames = 0;
    _increment_frame(frames);
    std::cout << "frames=" << frames << "\n";
    return 0;
}