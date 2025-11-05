// Context: Packet loss rate calculator

// Seed 044 — C: variables without underscore prefix
#include <iostream>
int main(){
    int sent = 1000; // C
    int lost = 15; // C
    float rate = static_cast<float>(lost) / sent * 100.0F;
    std::cout << "loss=" << rate << "%\n";
    return 0;
}