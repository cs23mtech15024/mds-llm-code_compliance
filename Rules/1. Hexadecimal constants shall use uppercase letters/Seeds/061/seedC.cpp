// Context: Lidar offset & flag

// Seed 095 — C: uppercase hex offset/flag
#include <iostream>
int main(){
    unsigned off =0x3C;  // C
    unsigned flag=0x5A;  // C
    std::cout<<"lidar off=0x"<<std::hex<<off
             <<" flag=0x"<<flag<<"\n";
    return 0;
}