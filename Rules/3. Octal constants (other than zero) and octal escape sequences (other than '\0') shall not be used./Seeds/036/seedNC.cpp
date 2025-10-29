// Context: Air traffic beacon identifier printer

#include <iostream>
int main(){
    char beacon[4]={'A','\102','\103','D'}; // NC: octal escapes \102='B', \103='C'
    for(char c:beacon) std::cout<<c;
    std::cout<<std::endl;
    return 0;
}
