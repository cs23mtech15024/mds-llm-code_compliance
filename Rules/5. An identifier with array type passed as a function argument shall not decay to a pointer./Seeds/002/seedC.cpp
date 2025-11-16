// Context: Image pixel buffer manipulation

// Seed 002 — C: pixel array by reference
#include <iostream>
void apply_filter(unsigned char (&pixels)[100]) { // C
    pixels[0] = 255;
    std::cout << "pixel=" << static_cast<int>(pixels[0]) << "\n";
}
int main(){
    unsigned char image[100];
    apply_filter(image);
    return 0;
}