// Context: PLC schedule minute markers

#include <iostream>
#include <array>
int main(){
    std::array<int,3> marks = {005, 015, 025}; // NC: octal 005=5, 015=13, 025=21
    for(int m:marks){
        std::cout<<"Mark="<<m<<" min\n";
    }
    return 0;
}
