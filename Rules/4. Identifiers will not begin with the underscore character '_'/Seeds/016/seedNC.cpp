// Context: Encryption key rotation counter

// Seed 016 — NC: counter variable starts with underscore
#include <iostream>
int main(){
    int _rotation_count = 5; // NC
    _rotation_count++;
    std::cout << "rotations=" << _rotation_count << "\n";
    return 0;
}