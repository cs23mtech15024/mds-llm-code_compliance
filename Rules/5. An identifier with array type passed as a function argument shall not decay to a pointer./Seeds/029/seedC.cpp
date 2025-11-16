// Context: Magnetometer heading samples

// Seed 029 — C: heading samples by reference
#include <iostream>
float get_heading(float (&samples)[20]) { // C
    return samples[0];
}
int main(){
    float mag_headings[20] = {45.5F};
    std::cout << "heading=" << get_heading(mag_headings) << "\n";
    return 0;
}