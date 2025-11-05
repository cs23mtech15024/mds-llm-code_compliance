// Context: Timestamp delta calculator

// Seed 038 — C: function without underscore prefix
#include <iostream>
long calc_delta(long t1, long t2) { // C
    return t2 - t1;
}
int main(){
    std::cout << "delta=" << calc_delta(1000, 5000) << "\n";
    return 0;
}