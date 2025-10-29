// Context: Wind turbine blade sensor encoder

#include <iostream>
#include <fstream>
int main(){
    std::ofstream enc("encoder.txt");
    char sync='\x30'; // C: hex escape \x30 = '0'
    enc<<"SYNC CHAR="<<sync<<std::endl;
    enc.close();
    std::cout<<"Encoder synchronization written."<<std::endl;
    return 0;
}
