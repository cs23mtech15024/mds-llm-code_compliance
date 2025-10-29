// Context: Rudder offset & mask tags

// Seed 090 — NC: lowercase hex offset/mask
#include <iostream>
int main(){
    unsigned offset=0xf;  // NC: 15
    unsigned mask  =0x3b; // NC: 59
    std::cout<<"rudder off=0x"<<std::hex<<offset
             <<" mask=0x"<<mask<<"\n";
    return 0;
}