// Context: Telemetry CSV writer with separator

#include <iostream>
#include <fstream>
int main(){
    std::ofstream out("telemetry.csv");
    char sep = '\011'; // NC: octal escape \011 = tab
    out<<"time"<<sep<<"altitude"<<sep<<"speed"<<"\n";
    out<<"1"<<sep<<"100"<<sep<<"20"<<"\n";
    out.close();
    std::cout<<"CSV written."<<std::endl;
    return 0;
}
