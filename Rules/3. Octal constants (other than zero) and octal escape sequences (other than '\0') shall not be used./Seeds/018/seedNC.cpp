// Context: Spacecraft temperature calibration constants

#include <iostream>
int main(){
    int coldLimit = 0150; // NC: octal constant 0150 = 104 decimal
    int hotLimit = 0200;  // NC: octal constant 0200 = 128 decimal
    std::cout<<"Temp range="<<coldLimit<<"-"<<hotLimit<<std::endl;
    return 0;
}
