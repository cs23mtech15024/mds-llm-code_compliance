// Context: Wind turbine blade sensor encoder

#include <iostream>
#include <fstream>
int main(){
    std::ofstream enc("encoder.txt");
    char sync='\060'; // NC: octal escape \060 = '0'
    enc<<"SYNC CHAR="<<sync<<std::endl;
    enc.close();
    std::cout<<"Encoder synchronization written."<<std::endl;
    return 0;
}
