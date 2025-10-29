// Context: Submarine sonar ping rate configuration

#include <iostream>
#include <fstream>
int main(){
    std::ofstream cfg("pingrate.cfg");
    int lowRate = 8;  // C: decimal equivalent of 010
    int highRate = 16; // C: decimal equivalent of 020
    cfg<<"LOW="<<lowRate<<" HIGH="<<highRate<<std::endl;
    cfg.close();
    std::cout<<"Ping rate limits written."<<std::endl;
    return 0;
}
