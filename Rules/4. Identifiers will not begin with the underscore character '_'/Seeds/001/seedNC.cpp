// Context: Financial transaction validator function

// Seed 001 — NC: function starts with underscore
#include <iostream>
int _validate_transaction(double amount) { // NC
    return (amount > 0.0 && amount < 1000000.0) ? 1 : 0;
}
int main(){
    std::cout << "valid=" << _validate_transaction(500.0) << "\n";
    return 0;
}