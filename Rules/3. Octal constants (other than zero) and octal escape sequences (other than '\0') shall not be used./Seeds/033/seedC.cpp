// Context: POS terminal log file permissions

#include <iostream>
#include <sys/stat.h>
#include <fstream>
int main(){
    std::ofstream f("pos.log");
    int mode = 0x1A4; // C: hex equivalent of 0644 (420 decimal)
    chmod("pos.log", mode);
    f<<"POS ready"<<std::endl;
    f.close();
    std::cout<<"Log initialized."<<std::endl;
    return 0;
}
