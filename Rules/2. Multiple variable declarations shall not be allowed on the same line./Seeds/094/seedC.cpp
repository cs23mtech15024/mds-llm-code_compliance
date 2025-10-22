// Context: Mars rover wheel slip compensator

#include <iostream>
int main(){
    double slip=0.0;     // C
    double set=0.15;     // C
    float gain=0.4F;     // C
    float cmd=0.0F;      // C
    int events=0;        // C
    int limits=0;        // C
    cmd += static_cast<float>((set-slip)*0.5);
    if(cmd>0.8F){ ++limits; }
    std::cout<<slip<<","<<set<<","<<gain<<","<<cmd<<","<<events<<","<<limits<<"\n";
    return 0;
}
