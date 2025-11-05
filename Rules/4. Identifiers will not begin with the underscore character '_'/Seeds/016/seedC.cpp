// Context: Encryption key rotation counter

// Seed 016 — C: counter variable without underscore prefix
#include <iostream>
int main(){
    int rotation_count = 5; // C
    rotation_count++;
    std::cout << "rotations=" << rotation_count << "\n";
    return 0;
}