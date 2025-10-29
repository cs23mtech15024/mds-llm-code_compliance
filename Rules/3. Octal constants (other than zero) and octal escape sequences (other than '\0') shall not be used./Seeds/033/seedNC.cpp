// Context: POS terminal log file permissions

#include <iostream>
#include <sys/stat.h>
#include <fstream>
int main(){
    std::ofstream f("pos.log");
    int mode = 0644; // NC: octal constant 0644 = 420
    chmod("pos.log", mode);
    f<<"POS ready"<<std::endl;
    f.close();
    std::cout<<"Log initialized."<<std::endl;
    return 0;
}
