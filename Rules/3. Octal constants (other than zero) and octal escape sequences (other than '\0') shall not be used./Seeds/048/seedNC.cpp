// Context: Machine learning batch size configurator

#include <iostream>
#include <fstream>
int main(){
    std::ofstream cfg("ml_config.txt");
    int batch = 0100; // NC: octal constant 0100 = 64
    cfg<<"BATCH_SIZE="<<batch<<std::endl;
    cfg.close();
    std::cout<<"ML config saved."<<std::endl;
    return 0;
}
