// Context: T/W mass & tag mask

// Seed 091 — NC: lowercase hex mass/mask
#include <iostream>
int main(){
    unsigned mass=0x190;  // NC: 400
    unsigned mask=0x7f;   // NC: 127
    std::cout<<"tw mass=0x"<<std::hex<<mass
             <<" mask=0x"<<mask<<"\n";
    return 0;
}