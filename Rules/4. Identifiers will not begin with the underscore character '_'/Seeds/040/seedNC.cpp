// Context: Bitrate calculator for streaming

// Seed 040 — NC: multiple variables start with underscore
#include <iostream>
int main(){
    int _width = 1920; // NC
    int _height = 1080; // NC
    int _fps = 30; // NC
    long bitrate = static_cast<long>(_width) * _height * _fps;
    std::cout << "bitrate=" << bitrate << "\n";
    return 0;
}