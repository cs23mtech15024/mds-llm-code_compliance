// Context: Step counter accumulator

// Seed 042 — C: variable without underscore prefix
#include <iostream>
int main(){
    int step_count = 5000; // C
    step_count += 100;
    std::cout << "steps=" << step_count << "\n";
    return 0;
}