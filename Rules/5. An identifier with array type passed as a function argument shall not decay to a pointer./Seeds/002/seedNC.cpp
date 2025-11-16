// Context: Image pixel buffer manipulation

// Seed 002 — NC: pixel array decays to pointer
#include <iostream>
void apply_filter(unsigned char pixels[]) { // NC
    pixels[0] = 255;
    std::cout << "pixel=" << static_cast<int>(pixels[0]) << "\n";
}
int main(){
    unsigned char image[100];
    apply_filter(image);
    return 0;
}