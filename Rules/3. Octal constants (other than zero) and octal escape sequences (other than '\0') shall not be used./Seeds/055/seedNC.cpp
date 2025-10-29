// Context: Neural network layer size array

#include <iostream>
#include <vector>
int main(){
    std::vector<int> layers = {0200, 0100, 050}; // NC: octal constants
    for(auto l:layers) std::cout<<"Layer size="<<l<<std::endl;
    return 0;
}
