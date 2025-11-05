// Context: Database connection counter

// Seed 006 — C: static variable without underscore prefix
#include <iostream>
int main(){
    static int connection_count = 0; // C
    connection_count++;
    std::cout << "connections=" << connection_count << "\n";
    return 0;
}