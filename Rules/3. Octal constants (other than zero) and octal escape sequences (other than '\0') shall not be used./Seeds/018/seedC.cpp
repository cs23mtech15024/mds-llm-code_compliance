// Context: Spacecraft temperature calibration constants

#include <iostream>
int main(){
    int coldLimit = 104; // C: decimal equivalent of 0150
    int hotLimit = 128;  // C: decimal equivalent of 0200
    std::cout<<"Temp range="<<coldLimit<<"-"<<hotLimit<<std::endl;
    return 0;
}
