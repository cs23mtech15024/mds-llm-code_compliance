// Context: Interrupt service flag

// Seed 053 — C: variable without underscore prefix
#include <iostream>
int main(){
    bool isr_triggered = true; // C
    std::cout << "isr=" << isr_triggered << "\n";
    return 0;
}