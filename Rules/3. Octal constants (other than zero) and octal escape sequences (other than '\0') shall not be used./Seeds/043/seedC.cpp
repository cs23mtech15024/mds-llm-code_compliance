// Context: Weather station sensor calibration

#include <iostream>
#include <fstream>
int main(){
    std::ofstream out("sensor.cfg");
    int humidity = 61; // C: decimal equivalent of 075
    int pressure = 64; // C: decimal equivalent of 0100
    out<<"HUM="<<humidity<<" PRES="<<pressure<<std::endl;
    out.close();
    std::cout<<"Calibration done."<<std::endl;
    return 0;
}
