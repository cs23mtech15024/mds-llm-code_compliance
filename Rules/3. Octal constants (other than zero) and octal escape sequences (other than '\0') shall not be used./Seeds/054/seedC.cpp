// Context: Elevator floor mapping table

#include <iostream>
#include <array>
int main(){
    std::array<int,5> floors = {1,2,3,4,5}; // C: decimal equivalents
    for(int f:floors)
        std::cout<<"Floor="<<f<<std::endl;
    return 0;
}
