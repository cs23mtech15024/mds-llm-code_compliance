// Context: Submarine sonar ping rate configuration

#include <iostream>
#include <fstream>
int main(){
    std::ofstream cfg("pingrate.cfg");
    int lowRate = 010;  // NC: octal constant 010 = 8 decimal
    int highRate = 020; // NC: octal constant 020 = 16 decimal
    cfg<<"LOW="<<lowRate<<" HIGH="<<highRate<<std::endl;
    cfg.close();
    std::cout<<"Ping rate limits written."<<std::endl;
    return 0;
}
