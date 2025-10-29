// Context: Lidar offset & flag

// Seed 095 — NC: lowercase hex offset/flag
#include <iostream>
int main(){
    unsigned off =0x3c;  // NC: 60
    unsigned flag=0x5a;  // NC: 90
    std::cout<<"lidar off=0x"<<std::hex<<off
             <<" flag=0x"<<flag<<"\n";
    return 0;
}