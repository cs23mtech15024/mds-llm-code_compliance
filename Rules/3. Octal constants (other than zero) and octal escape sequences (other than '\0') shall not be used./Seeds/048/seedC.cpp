// Context: Machine learning batch size configurator

#include <iostream>
#include <fstream>
int main(){
    std::ofstream cfg("ml_config.txt");
    int batch = 64; // C: decimal equivalent of 0100
    cfg<<"BATCH_SIZE="<<batch<<std::endl;
    cfg.close();
    std::cout<<"ML config saved."<<std::endl;
    return 0;
}
