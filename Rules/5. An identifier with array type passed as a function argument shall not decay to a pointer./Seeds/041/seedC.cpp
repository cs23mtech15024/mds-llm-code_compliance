// Context: Proximity sensor threshold array

// Seed 041 — C: threshold array by reference
#include <iostream>
void set_thresholds(int (&thresholds)[8]) { // C
    thresholds[0] = 50;
    std::cout << "threshold0=" << thresholds[0] << "\n";
}
int main(){
    int proximity_thresholds[8] = {0};
    set_thresholds(proximity_thresholds);
    return 0;
}