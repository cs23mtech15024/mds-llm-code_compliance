// Context: Solar panel inverter efficiency reader

#include <iostream>
#include <fstream>
int main(){
    std::ofstream log("eff.txt");
    int mode = 0644; // NC: octal constant 0644 = 420
    log<<"MODE="<<mode<<std::endl;
    log.close();
    std::cout<<"Efficiency mode written."<<std::endl;
    return 0;
}
