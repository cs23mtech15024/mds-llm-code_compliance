// Context: Pipeline sensor mode register mask

#include <iostream>
#include <bitset>
int main(){
    int mode = 0400; // NC: octal constant 0400 = 256
    std::bitset<10> bits(mode);
    std::cout<<"Register mask="<<bits<<std::endl;
    return 0;
}
