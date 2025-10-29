// Context: Pipeline sensor mode register mask

#include <iostream>
#include <bitset>
int main(){
    int mode = 256; // C: decimal equivalent of 0400
    std::bitset<10> bits(mode);
    std::cout<<"Register mask="<<bits<<std::endl;
    return 0;
}
