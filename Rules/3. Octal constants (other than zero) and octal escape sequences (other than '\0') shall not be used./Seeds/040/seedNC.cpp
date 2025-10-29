// Context: Power grid relay control mask

#include <iostream>
#include <bitset>
int main(){
    int mask = 0777; // NC: octal constant 0777 = 511 decimal
    std::bitset<10> relays(mask);
    std::cout<<"Relay mask="<<relays<<std::endl;
    return 0;
}
