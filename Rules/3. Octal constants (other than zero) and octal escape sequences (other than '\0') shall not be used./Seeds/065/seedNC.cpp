// Context: Genomic sequencer read length configurator

#include <iostream>
#include <fstream>
int main(){
    std::ofstream cfg("seq.conf");
    int readLen = 0250; // NC: octal constant 0250 = 168
    cfg<<"READ_LENGTH="<<readLen<<std::endl;
    cfg.close();
    std::cout<<"Sequencer configured."<<std::endl;
    return 0;
}
