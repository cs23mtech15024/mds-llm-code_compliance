// Context: Automotive radar pulse generator

#include <iostream>
#include <cmath>
int main(){
    int pulseWidth = 5; // C: decimal literal
    int count = 8;      // C: decimal literal
    double signal = std::sin(pulseWidth * count);
    std::cout<<"Pulse signal="<<signal<<std::endl;
    return 0;
}
