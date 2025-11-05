// Context: Retry attempt counter

// Seed 027 — NC: variable starts with underscore
#include <iostream>
int main(){
    int _retry_count = 0; // NC
    _retry_count++;
    std::cout << "retries=" << _retry_count << "\n";
    return 0;
}