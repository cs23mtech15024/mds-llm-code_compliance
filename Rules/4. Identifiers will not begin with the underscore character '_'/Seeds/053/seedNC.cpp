// Context: Interrupt service flag

// Seed 053 — NC: variable starts with underscore
#include <iostream>
int main(){
    bool _isr_triggered = true; // NC
    std::cout << "isr=" << _isr_triggered << "\n";
    return 0;
}