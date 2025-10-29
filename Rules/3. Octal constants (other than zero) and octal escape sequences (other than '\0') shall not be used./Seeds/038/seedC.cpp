// Context: Space station environmental log writer

#include <iostream>
#include <fstream>
int main(){
    std::ofstream out("env.log");
    char colon=':'; // C: direct literal
    out<<"O2"<<colon<<"98"<<std::endl;
    out.close();
    std::cout<<"Environment logged."<<std::endl;
    return 0;
}
