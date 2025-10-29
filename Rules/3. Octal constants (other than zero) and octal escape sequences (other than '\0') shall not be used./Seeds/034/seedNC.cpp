// Context: Marine sonar depth calibration writer

#include <iostream>
#include <fstream>
int main(){
    std::ofstream depth("depth.dat");
    int offset = 010; // NC: octal constant 010 = 8
    depth<<"OFFSET="<<offset<<std::endl;
    depth.close();
    std::cout<<"Depth calibration written."<<std::endl;
    return 0;
}
