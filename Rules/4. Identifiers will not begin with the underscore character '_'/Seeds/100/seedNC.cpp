// Context: Heartbeat interval checker

// Seed 100 — NC: function and parameter start with underscore
#include <iostream>
bool _check_heartbeat(int _interval) { // NC
    return _interval > 0 && _interval < 10000;
}
int main(){
    std::cout << "valid=" << _check_heartbeat(1000) << "\n";
    return 0;
}