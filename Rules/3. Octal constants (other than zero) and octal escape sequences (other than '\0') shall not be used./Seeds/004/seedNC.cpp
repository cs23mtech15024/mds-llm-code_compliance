// Context: Embedded flight recorder calibration data

#include <iostream>
#include <iomanip>
int main(){
    int roll=07;  // NC: octal literal
    int pitch=010; // NC
    int yaw=012;   // NC
    std::cout<<"Roll="<<roll<<", Pitch="<<pitch<<", Yaw="<<yaw<<std::endl;
    return 0;
}
