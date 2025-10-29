// Context: Audio signal analyzer sample counter

#include <iostream>
int main(){
    int samples = 0440;  // NC: octal constant
    int channels = 010;  // NC: octal constant
    int total = samples * channels;
    std::cout<<"Total audio samples: "<<total<<std::endl;
    return 0;
}
