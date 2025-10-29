// Context: Mars rover wheel slip compensator

#include <iostream>
int main(){
    double slip=0.0, set=0.15;     // NC
    float gain=0.4F, cmd=0.0F;     // NC
    int events=0, limits=0;        // NC
    cmd += static_cast<float>((set-slip)*0.5);
    if(cmd>0.8F){ ++limits; }
    std::cout<<slip<<","<<set<<","<<gain<<","<<cmd<<","<<events<<","<<limits<<"\n";
    return 0;
}
