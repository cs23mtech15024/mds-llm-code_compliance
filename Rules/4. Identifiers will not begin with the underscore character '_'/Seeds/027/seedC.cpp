// Context: Retry attempt counter

// Seed 027 — C: variable without underscore prefix
#include <iostream>
int main(){
    int retry_count = 0; // C
    retry_count++;
    std::cout << "retries=" << retry_count << "\n";
    return 0;
}