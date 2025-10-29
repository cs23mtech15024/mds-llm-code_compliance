// Context: Data center fan control threshold

#include <iostream>
#include <fstream>
int main(){
    std::ofstream cfg("fan.cfg");
    int low = 050; // NC: octal constant 050 = 40
    int high = 075; // NC: octal constant 075 = 61
    cfg<<"FAN_LOW="<<low<<" HIGH="<<high<<std::endl;
    cfg.close();
    std::cout<<"Fan threshold saved."<<std::endl;
    return 0;
}
