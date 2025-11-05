// Context: Event timestamp recorder

// Seed 048 — C: variable without underscore prefix
#include <iostream>
int main(){
    long event_time = 123456789L; // C
    std::cout << "time=" << event_time << "\n";
    return 0;
}