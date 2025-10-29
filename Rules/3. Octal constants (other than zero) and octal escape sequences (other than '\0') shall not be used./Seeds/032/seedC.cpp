// Context: PLC schedule minute markers

#include <iostream>
#include <array>
int main(){
    std::array<int,3> marks = {5, 13, 21}; // C: decimal equivalents
    for(int m:marks){
        std::cout<<"Mark="<<m<<" min\n";
    }
    return 0;
}
