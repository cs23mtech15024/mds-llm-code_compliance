// Context: Augmented reality marker ID generator

#include <iostream>
#include <array>
int main(){
    std::array<int,4> markers = {0100, 0200, 0300, 0400}; // NC: octal
    for(int m:markers) std::cout<<"Marker ID="<<m<<std::endl;
    return 0;
}
