// Context: Audio signal analyzer sample counter

#include <iostream>
int main(){
    int samples = 288;   // C: decimal equivalent of 0440 octal
    int channels = 8;    // C: decimal equivalent of 010 octal
    int total = samples * channels;
    std::cout<<"Total audio samples: "<<total<<std::endl;
    return 0;
}
