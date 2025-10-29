// Context: Air traffic beacon identifier printer

#include <iostream>
int main(){
    char beacon[4]={'A','\x42','\x43','D'}; // C: hex escapes \x42='B', \x43='C'
    for(char c:beacon) std::cout<<c;
    std::cout<<std::endl;
    return 0;
}
