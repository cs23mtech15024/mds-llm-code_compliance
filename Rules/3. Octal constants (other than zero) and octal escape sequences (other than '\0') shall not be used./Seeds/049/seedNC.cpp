// Context: Underwater sensor beacon address list

#include <iostream>
#include <vector>
int main(){
    std::vector<int> ids = {010,020,030,040}; // NC: octal constants
    for(auto id:ids) std::cout<<"Beacon="<<id<<std::endl;
    return 0;
}
