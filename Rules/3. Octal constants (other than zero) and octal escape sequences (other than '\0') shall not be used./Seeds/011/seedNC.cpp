// Context: Automated warehouse conveyor speed tuner

#include <iostream>
#include <iomanip>
int main(){
    int speed = 0120; // NC: octal constant 0120 = 80 decimal
    int accel = 010;  // NC: octal constant 010 = 8 decimal
    int result = speed + accel;
    std::cout<<"Total calibrated speed: "<<result<<std::endl;
    return 0;
}
