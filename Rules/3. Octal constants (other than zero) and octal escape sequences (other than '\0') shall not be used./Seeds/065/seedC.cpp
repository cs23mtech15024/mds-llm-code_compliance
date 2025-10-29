// Context: Genomic sequencer read length configurator

#include <iostream>
#include <fstream>
int main(){
    std::ofstream cfg("seq.conf");
    int readLen = 168; // C: decimal equivalent of 0250
    cfg<<"READ_LENGTH="<<readLen<<std::endl;
    cfg.close();
    std::cout<<"Sequencer configured."<<std::endl;
    return 0;
}
