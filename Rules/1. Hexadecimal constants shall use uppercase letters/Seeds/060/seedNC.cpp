// Context: Prop sync delay & mask

// Seed 092 — NC: lowercase hex delay/mask
#include <iostream>
int main(){
    unsigned delay=0x21;  // NC: 33
    unsigned mask =0x0f;  // NC: 15
    std::cout<<"prop delay=0x"<<std::hex<<delay
             <<" mask=0x"<<mask<<"\n";
    return 0;
}