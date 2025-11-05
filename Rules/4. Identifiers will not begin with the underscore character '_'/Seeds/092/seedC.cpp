// Context: Thread pool worker count

// Seed 092 — C: variable without underscore prefix
#include <iostream>
int main(){
    int worker_threads = 4; // C
    std::cout << "workers=" << worker_threads << "\n";
    return 0;
}