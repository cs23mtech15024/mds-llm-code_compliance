// Context: Heartbeat interval checker

// Seed 100 — C: function and parameter without underscore prefix
#include <iostream>
bool check_heartbeat(int interval) { // C
    return interval > 0 && interval < 10000;
}
int main(){
    std::cout << "valid=" << check_heartbeat(1000) << "\n";
    return 0;
}