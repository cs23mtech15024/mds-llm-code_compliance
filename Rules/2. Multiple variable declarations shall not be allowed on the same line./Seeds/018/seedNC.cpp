// Context: Robotic welder seam tracker

#include <iostream>
int main(){
    float offset=0.0F, speed=0.0F;    // NC
    double kp=0.6, ki=0.02;           // NC
    int good=0, bad=0;                // NC
    offset+=0.05F; speed=0.8F;
    std::cout<<offset<<","<<speed<<","<<kp<<","<<ki<<","<<good<<","<<bad<<"\n";
    return 0;
}
