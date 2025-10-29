// Context: Quantum qubit state serializer

#include <iostream>
int main(){
    int states[4] = {00, 01, 010, 011}; // NC: octal constants
    for(int s:states) std::cout<<"State="<<s<<std::endl;
    return 0;
}
