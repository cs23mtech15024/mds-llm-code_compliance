// Context: Weather station sensor calibration

#include <iostream>
#include <fstream>
int main(){
    std::ofstream out("sensor.cfg");
    int humidity = 075; // NC: octal constant 075 = 61
    int pressure = 0100; // NC: octal constant 0100 = 64
    out<<"HUM="<<humidity<<" PRES="<<pressure<<std::endl;
    out.close();
    std::cout<<"Calibration done."<<std::endl;
    return 0;
}
