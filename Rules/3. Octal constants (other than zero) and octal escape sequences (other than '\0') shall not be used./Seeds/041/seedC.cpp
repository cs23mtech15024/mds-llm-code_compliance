// Context: Data center fan control threshold

#include <iostream>
#include <fstream>
int main(){
    std::ofstream cfg("fan.cfg");
    int low = 40; // C: decimal equivalent of 050
    int high = 61; // C: decimal equivalent of 075
    cfg<<"FAN_LOW="<<low<<" HIGH="<<high<<std::endl;
    cfg.close();
    std::cout<<"Fan threshold saved."<<std::endl;
    return 0;
}
