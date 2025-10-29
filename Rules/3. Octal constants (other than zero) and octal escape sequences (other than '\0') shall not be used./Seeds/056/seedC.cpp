// Context: Security system passcode encoder

#include <iostream>
int main(){
    char code[4]={'1','2','3','4'}; // C: direct literals
    for(char c:code) std::cout<<c;
    std::cout<<std::endl;
    return 0;
}
