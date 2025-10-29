// Context: Factory temperature sensor threshold

#include <iostream>
#include <fstream>
int main(){
    std::ofstream cfg("temp.cfg");
    int low = 0150; // NC: octal constant 0150 = 104
    int high = 0200; // NC: octal constant 0200 = 128
    cfg<<"RANGE="<<low<<"-"<<high<<std::endl;
    cfg.close();
    std::cout<<"Thresholds saved."<<std::endl;
    return 0;
}
