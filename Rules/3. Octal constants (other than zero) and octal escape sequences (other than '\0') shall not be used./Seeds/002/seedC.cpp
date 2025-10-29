// Context: Robot sensor configuration file generator

#include <iostream>
#include <fstream>
int main(){
    std::ofstream cfg("sensor.cfg");
    cfg<<"GAIN=7"<<std::endl; // C: decimal constant
    cfg<<"OFFSET=10"<<std::endl; // C: decimal equivalent of 012
    cfg.close();
    std::cout<<"Configuration written."<<std::endl;
    return 0;
}
