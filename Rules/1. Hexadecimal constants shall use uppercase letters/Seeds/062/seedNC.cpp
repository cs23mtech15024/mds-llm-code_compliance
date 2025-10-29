// Context: Turbulence ref & mask

// Seed 096 — NC: lowercase hex ref/mask
#include <iostream>
int main(){
    unsigned ref =0x17;  // NC: 23
    unsigned mask=0x7a;  // NC: 122
    std::cout<<"turb ref=0x"<<std::hex<<ref
             <<" mask=0x"<<mask<<"\n";
    return 0;
}