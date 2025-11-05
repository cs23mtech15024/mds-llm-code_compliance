// Context: Timestamp delta calculator

// Seed 038 — NC: function starts with underscore
#include <iostream>
long _calc_delta(long t1, long t2) { // NC
    return t2 - t1;
}
int main(){
    std::cout << "delta=" << _calc_delta(1000, 5000) << "\n";
    return 0;
}