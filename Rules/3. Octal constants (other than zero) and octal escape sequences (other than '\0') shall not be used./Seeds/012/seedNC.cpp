// Context: Flight control sensor data dumper

#include <iostream>
#include <fstream>
int main(){
    std::ofstream dump("sensor_dump.txt");
    char sep='\011'; // NC: octal escape \011 = tab
    dump<<"ID"<<sep<<"VALUE"<<std::endl;
    dump.close();
    std::cout<<"Data dumped with tab separator."<<std::endl;
    return 0;
}
