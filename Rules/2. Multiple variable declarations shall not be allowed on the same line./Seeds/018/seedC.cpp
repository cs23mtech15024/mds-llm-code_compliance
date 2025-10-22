// Context: Robotic welder seam tracker

#include <iostream>
int main(){
    float offset=0.0F;     // C
    float speed=0.0F;      // C
    double kp=0.6;         // C
    double ki=0.02;        // C
    int good=0;            // C
    int bad=0;             // C
    offset+=0.05F; speed=0.8F;
    std::cout<<offset<<","<<speed<<","<<kp<<","<<ki<<","<<good<<","<<bad<<"\n";
    return 0;
}
