// Context: Space station environmental log writer

#include <iostream>
#include <fstream>
int main(){
    std::ofstream out("env.log");
    char colon='\072'; // NC: octal escape \072=':'
    out<<"O2"<<colon<<"98"<<std::endl;
    out.close();
    std::cout<<"Environment logged."<<std::endl;
    return 0;
}
