// Context: Loop iteration counter

// Seed 086 — NC: variable starts with underscore
#include <iostream>
int main(){
    int _iteration = 0; // NC
    for(_iteration = 0; _iteration < 10; _iteration++){
        // process
    }
    std::cout << "iters=" << _iteration << "\n";
    return 0;
}