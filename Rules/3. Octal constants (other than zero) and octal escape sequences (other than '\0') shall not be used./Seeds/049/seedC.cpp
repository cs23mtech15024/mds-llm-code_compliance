// Context: Underwater sensor beacon address list

#include <iostream>
#include <vector>
int main(){
    std::vector<int> ids = {8,16,24,32}; // C: decimal equivalents
    for(auto id:ids) std::cout<<"Beacon="<<id<<std::endl;
    return 0;
}
