// Context: Bitrate calculator for streaming

// Seed 040 — C: variables without underscore prefix
#include <iostream>
int main(){
    int width = 1920; // C
    int height = 1080; // C
    int fps = 30; // C
    long bitrate = static_cast<long>(width) * height * fps;
    std::cout << "bitrate=" << bitrate << "\n";
    return 0;
}