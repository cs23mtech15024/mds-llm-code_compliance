// Context: Data logger mode setup for industrial controller

#include <iostream>
#include <fstream>
#include <sys/stat.h>
int main(){
    int mode = 420; // C: decimal equivalent of 0644
    std::ofstream log("controller.log");
    log<<"Mode set to: "<<mode<<std::endl;
    chmod("controller.log", mode);
    std::cout<<"Logger initialized."<<std::endl;
    return 0;
}
