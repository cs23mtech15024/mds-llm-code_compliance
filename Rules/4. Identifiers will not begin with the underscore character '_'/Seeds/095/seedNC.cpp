// Context: Semaphore initial count

// Seed 095 — NC: variable starts with underscore
#include <iostream>
int main(){
    int _sem_count = 5; // NC
    std::cout << "sem_init=" << _sem_count << "\n";
    return 0;
}