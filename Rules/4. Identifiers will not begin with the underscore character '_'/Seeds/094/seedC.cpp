// Context: Mutex lock timeout value

// Seed 094 — C: variable without underscore prefix
#include <iostream>
int main(){
    int lock_timeout = 1000; // C
    std::cout << "timeout=" << lock_timeout << "ms\n";
    return 0;
}