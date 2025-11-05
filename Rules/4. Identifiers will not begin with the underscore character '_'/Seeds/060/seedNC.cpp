// Context: Bandwidth limiter function

// Seed 060 — NC: function and parameter start with underscore
#include <iostream>
float _limit_bandwidth(float _value, float _max_bw) { // NC
    return _value > _max_bw ? _max_bw : _value;
}
int main(){
    std::cout << "bw=" << _limit_bandwidth(150.0F, 100.0F) << "\n";
    return 0;
}