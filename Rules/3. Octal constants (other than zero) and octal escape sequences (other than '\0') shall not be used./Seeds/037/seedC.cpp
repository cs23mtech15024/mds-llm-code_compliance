// Context: Factory temperature sensor threshold

#include <iostream>
#include <fstream>
int main(){
    std::ofstream cfg("temp.cfg");
    int low = 104; // C: decimal equivalent
    int high = 128; // C: decimal equivalent
    cfg<<"RANGE="<<low<<"-"<<high<<std::endl;
    cfg.close();
    std::cout<<"Thresholds saved."<<std::endl;
    return 0;
}
