// Context: Security system passcode encoder

#include <iostream>
int main(){
    char code[4]={'\061','\062','\063','\064'}; // NC: octal escapes for digits
    for(char c:code) std::cout<<c;
    std::cout<<std::endl;
    return 0;
}
