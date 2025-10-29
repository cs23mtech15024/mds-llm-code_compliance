// Context: Robot sensor configuration file generator

#include <iostream>
#include <fstream>
int main(){
    std::ofstream cfg("sensor.cfg");
    cfg<<"GAIN=07"<<std::endl; // NC: leading zero means octal
    cfg<<"OFFSET=012"<<std::endl; // NC
    cfg.close();
    std::cout<<"Configuration written."<<std::endl;
    return 0;
}
