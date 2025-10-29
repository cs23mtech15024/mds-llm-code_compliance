// Context: Radar mode & frame mask tags

// Seed 084 — NC: lowercase hex mode/frame
#include <iostream>
int main(){
    unsigned mode =0xc;    // NC: 12
    unsigned frame=0x7f;   // NC: 127
    std::cout<<"radar mode=0x"<<std::hex<<mode
             <<" frame=0x"<<frame<<"\n";
    return 0;
}