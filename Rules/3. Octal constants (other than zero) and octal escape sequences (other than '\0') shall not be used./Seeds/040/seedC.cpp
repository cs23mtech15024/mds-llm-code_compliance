// Context: Power grid relay control mask

#include <iostream>
#include <bitset>
int main(){
    int mask = 511; // C: decimal equivalent of 0777
    std::bitset<10> relays(mask);
    std::cout<<"Relay mask="<<relays<<std::endl;
    return 0;
}
