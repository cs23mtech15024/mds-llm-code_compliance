// Context: Mutex lock timeout value

// Seed 094 — NC: variable starts with underscore
#include <iostream>
int main(){
    int _lock_timeout = 1000; // NC
    std::cout << "timeout=" << _lock_timeout << "ms\n";
    return 0;
}