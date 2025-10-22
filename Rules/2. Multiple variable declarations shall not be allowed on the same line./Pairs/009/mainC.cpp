// Context: Video analytics motion trigger

// ------ Compliant Program (009_c.cpp)
// Compliant version: one declarator per declaration.
#include <iostream>
#include <cmath>
#include <cstddef>
namespace vid_009 {
    struct Stats { int frames; int detections; }; // OK
    static bool motion(float a,float h){ return std::fabs(a)>h; }
    void run(){
        float thresh=0.4F;                 // C
        float hyster=0.2F;                 // C
        int detections=0;                  // C
        int frames=0;                      // C
        bool armed=true;                   // C
        bool alarm=false;                  // C
        for (int i=0;i<12;++i){
            float a = (i%3==0)?0.5F:0.1F;
            frames++;
            if (armed && motion(a,thresh)) {
                detections++;
                alarm = (alarm||a>thresh+hyster);
            }
        }
        std::cout<<"f="<<frames<<" d="<<detections<<" alarm="<<alarm<<"\n";
    }
}
int main(){ vid_009::run(); return 0; }
