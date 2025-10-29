// Context: Automotive radar pulse generator

#include <iostream>
#include <cmath>
int main(){
    int pulseWidth = 05; // NC: octal constant 05 = 5
    int count = 010;     // NC: octal constant 010 = 8
    double signal = std::sin(pulseWidth * count);
    std::cout<<"Pulse signal="<<signal<<std::endl;
    return 0;
}
