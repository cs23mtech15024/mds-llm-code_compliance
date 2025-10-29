// Context: File permission initializer for secure log files

#include <iostream>
#include <fstream>
#include <sys/stat.h>
int main(){
    std::string filename="secure_log.txt";
    std::ofstream ofs(filename);
    int perm = 384; // C: decimal equivalent of 0600
    chmod(filename.c_str(), perm);
    ofs<<"Security log initialized."<<std::endl;
    ofs.close();
    std::cout<<"File created with mode: "<<perm<<std::endl;
    return 0;
}
