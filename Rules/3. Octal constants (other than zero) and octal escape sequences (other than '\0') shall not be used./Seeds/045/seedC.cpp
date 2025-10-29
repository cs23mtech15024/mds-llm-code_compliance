// Context: Solar panel inverter efficiency reader

#include <iostream>
#include <fstream>
int main(){
    std::ofstream log("eff.txt");
    int mode = 420; // C: decimal equivalent of 0644
    log<<"MODE="<<mode<<std::endl;
    log.close();
    std::cout<<"Efficiency mode written."<<std::endl;
    return 0;
}
