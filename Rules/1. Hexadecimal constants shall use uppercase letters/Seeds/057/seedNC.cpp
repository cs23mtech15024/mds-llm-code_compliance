// Context: Idle-speed offset & flag tags

// Seed 085 — NC: lowercase hex offset/flag
#include <iostream>
int main(){
    unsigned offset=0x3;   // NC: 3
    unsigned flag  =0xbe;  // NC: 190
    std::cout<<"idle off=0x"<<std::hex<<offset
             <<" flag=0x"<<flag<<"\n";
    return 0;
}