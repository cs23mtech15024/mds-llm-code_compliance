// Context: Quantum qubit state serializer

#include <iostream>
int main(){
    int states[4] = {0, 1, 8, 9}; // C: decimal equivalents
    for(int s:states) std::cout<<"State="<<s<<std::endl;
    return 0;
}
