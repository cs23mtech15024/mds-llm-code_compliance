// Context: Marine sonar depth calibration writer

#include <iostream>
#include <fstream>
int main(){
    std::ofstream depth("depth.dat");
    int offset = 8; // C: decimal literal
    depth<<"OFFSET="<<offset<<std::endl;
    depth.close();
    std::cout<<"Depth calibration written."<<std::endl;
    return 0;
}
