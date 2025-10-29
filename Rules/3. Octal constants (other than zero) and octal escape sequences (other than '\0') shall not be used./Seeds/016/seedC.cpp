// Context: Maritime sonar ping signal generator

#include <iostream>
#include <cmath>
int main(){
    int baseFreq = 288;  // C: decimal equivalent of 0440
    double amplitude = 7; // C: decimal
    double signal = std::sin(static_cast<double>(baseFreq)) * amplitude;
    std::cout<<"Ping signal="<<signal<<std::endl;
    return 0;
}
