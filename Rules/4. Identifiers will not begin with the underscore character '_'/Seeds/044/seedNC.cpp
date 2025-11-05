// Context: Packet loss rate calculator

// Seed 044 — NC: variables start with underscore
#include <iostream>
int main(){
    int _sent = 1000; // NC
    int _lost = 15; // NC
    float rate = static_cast<float>(_lost) / _sent * 100.0F;
    std::cout << "loss=" << rate << "%\n";
    return 0;
}