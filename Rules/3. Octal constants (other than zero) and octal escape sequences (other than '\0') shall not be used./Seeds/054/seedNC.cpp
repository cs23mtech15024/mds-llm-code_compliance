// Context: Elevator floor mapping table

#include <iostream>
#include <array>
int main(){
    std::array<int,5> floors = {01,02,03,04,05}; // NC: octal constants
    for(int f:floors)
        std::cout<<"Floor="<<f<<std::endl;
    return 0;
}
