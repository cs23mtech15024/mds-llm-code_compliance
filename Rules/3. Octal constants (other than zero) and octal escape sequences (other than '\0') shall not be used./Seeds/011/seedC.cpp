// Context: Automated warehouse conveyor speed tuner

#include <iostream>
#include <iomanip>
int main(){
    int speed = 80;  // C: decimal equivalent of 0120
    int accel = 8;   // C: decimal equivalent of 010
    int result = speed + accel;
    std::cout<<"Total calibrated speed: "<<result<<std::endl;
    return 0;
}
