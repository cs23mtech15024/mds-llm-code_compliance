// Context: Neural network layer size array

#include <iostream>
#include <vector>
int main(){
    std::vector<int> layers = {128, 64, 40}; // C: decimal equivalents
    for(auto l:layers) std::cout<<"Layer size="<<l<<std::endl;
    return 0;
}
