// Context: Autonomous drone altitude hold loop

#include <iostream>
int main(){
    float error=0.0F, integral=0.0F; // NC: multiple declarators
    double kp=1.1, ki=0.05;          // NC
    int samples=0, drops=0;          // NC
    error += 0.2F; integral += error;
    std::cout<<kp<<","<<ki<<","<<samples<<","<<drops<<"\n";
    return 0;
}
