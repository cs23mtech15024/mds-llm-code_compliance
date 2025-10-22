// Context: Autonomous drone altitude hold loop

// ------ Compliant Program (001_c.cpp)
// Fix: split every declaration so that each has a single declarator (8-0-1).
#include <iostream>
#include <iomanip>
#include <array>
#include <cstddef>
namespace alt_001 {
    struct State { float alt; float vel; }; // OK
    static float clamp(float v, float lo, float hi){ return v < lo ? lo : (v > hi ? hi : v); }
    void step(){
        float error=0.0F;                    // C
        float integral=0.0F;                 // C
        double kp=1.10;                      // C
        double ki=0.05;                      // C
        int samples=0;                       // C
        int drops=0;                         // C
        State s{0.0F, 0.0F};                 // OK
        const float dt=0.02F;                // OK
        std::array<float,6U> refs{1.0F,1.1F,0.9F,1.2F,1.0F,0.8F};
        for (std::size_t i=0U; i<refs.size(); ++i){
            float set=refs[i];
            error = set - s.alt;
            integral += error * dt;
            float u = static_cast<float>(kp)*error + static_cast<float>(ki)*integral;
            u = clamp(u,-2.0F,2.0F);
            s.vel += u * dt;
            s.alt += s.vel * dt;
            samples++;
            if ((i%3U)==0U) { drops++; }
            if ((i%2U)==0U) {
                std::cout<<"t="<<i<<" alt="<<std::fixed<<std::setprecision(2)<<s.alt
                         <<" err="<<error<<" u="<<u<<"\n";
            }
        }
        std::cout<<"done samples="<<samples<<" drops="<<drops<<"\n";
    }
}
int main(){ alt_001::step(); return 0; }
