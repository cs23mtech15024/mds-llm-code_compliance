// Context: Autonomous drone altitude hold loop

#include <iostream>
int main(){
    float error=0.0F;     // C: one declarator
    float integral=0.0F;  // C
    double kp=1.1;        // C
    double ki=0.05;       // C
    int samples=0;        // C
    int drops=0;          // C
    error += 0.2F; integral += error;
    std::cout<<kp<<","<<ki<<","<<samples<<","<<drops<<"\n";
    return 0;
}
