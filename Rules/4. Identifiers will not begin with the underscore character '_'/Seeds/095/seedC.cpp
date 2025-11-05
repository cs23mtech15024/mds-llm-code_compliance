// Context: Semaphore initial count

// Seed 095 — C: variable without underscore prefix
#include <iostream>
int main(){
    int sem_count = 5; // C
    std::cout << "sem_init=" << sem_count << "\n";
    return 0;
}