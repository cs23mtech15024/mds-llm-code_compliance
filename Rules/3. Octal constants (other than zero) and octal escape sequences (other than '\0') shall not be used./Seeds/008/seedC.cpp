// Context: Smart parking meter configuration updater

#include <iostream>
#include <fstream>
int main(){
    std::ofstream cfg("parking.conf");
    int timeout = 24;    // C: decimal equivalent of 030
    int rate = 10;       // C: decimal equivalent of 012
    cfg<<"TIMEOUT="<<timeout<<"\n";
    cfg<<"RATE="<<rate<<"\n";
    cfg.close();
    std::cout<<"Configuration updated."<<std::endl;
    return 0;
}
