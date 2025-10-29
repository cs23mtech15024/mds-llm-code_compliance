// Context: Augmented reality marker ID generator

#include <iostream>
#include <array>
int main(){
    std::array<int,4> markers = {64, 128, 192, 256}; // C: decimal
    for(int m:markers) std::cout<<"Marker ID="<<m<<std::endl;
    return 0;
}
