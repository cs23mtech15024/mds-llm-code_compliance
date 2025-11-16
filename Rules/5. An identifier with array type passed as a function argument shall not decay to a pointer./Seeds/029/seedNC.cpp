// Context: Magnetometer heading samples

// Seed 029 — NC: heading samples decay to pointer
#include <iostream>
float get_heading(float samples[]) { // NC
    return samples[0];
}
int main(){
    float mag_headings[20] = {45.5F};
    std::cout << "heading=" << get_heading(mag_headings) << "\n";
    return 0;
}