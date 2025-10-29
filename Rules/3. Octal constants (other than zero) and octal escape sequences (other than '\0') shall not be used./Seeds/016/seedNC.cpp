// Context: Maritime sonar ping signal generator

#include <iostream>
#include <cmath>
int main(){
    int baseFreq = 0440;   // NC: octal integer 0440 = 288
    double amplitude = 07; // NC: octal integer 07 = 7 (use decimal)
    double signal = std::sin(static_cast<double>(baseFreq)) * amplitude;
    std::cout<<"Ping signal="<<signal<<std::endl;
    return 0;
}
