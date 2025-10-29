// Context: Camera firmware version fields

#include <iostream>
int main(){
    int major = 010; // NC: octal constant 010 = 8
    int minor = 012; // NC: octal constant 012 = 10
    int patch = 005; // NC: octal constant 005 = 5
    std::cout<<"FW="<<major<<"."<<minor<<"."<<patch<<"\n";
    return 0;
}
