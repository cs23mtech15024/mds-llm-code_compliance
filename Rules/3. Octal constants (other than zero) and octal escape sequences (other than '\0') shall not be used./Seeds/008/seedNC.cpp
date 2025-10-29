// Context: Smart parking meter configuration updater

#include <iostream>
#include <fstream>
int main(){
    std::ofstream cfg("parking.conf");
    int timeout = 030;   // NC: octal constant, 030 = 24 decimal
    int rate = 012;      // NC: octal constant, 012 = 10 decimal
    cfg<<"TIMEOUT="<<timeout<<"\n";
    cfg<<"RATE="<<rate<<"\n";
    cfg.close();
    std::cout<<"Configuration updated."<<std::endl;
    return 0;
}
