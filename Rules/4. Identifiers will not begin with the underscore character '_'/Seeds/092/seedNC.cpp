// Context: Thread pool worker count

// Seed 092 — NC: variable starts with underscore
#include <iostream>
int main(){
    int _worker_threads = 4; // NC
    std::cout << "workers=" << _worker_threads << "\n";
    return 0;
}