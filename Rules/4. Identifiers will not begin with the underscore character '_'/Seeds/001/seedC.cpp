// Context: Financial transaction validator function

// Seed 001 — C: function without underscore prefix
#include <iostream>
int validate_transaction(double amount) { // C
    return (amount > 0.0 && amount < 1000000.0) ? 1 : 0;
}
int main(){
    std::cout << "valid=" << validate_transaction(500.0) << "\n";
    return 0;
}