// Context: Autonomous drone altitude hold loop

// ------ Non-Compliant Program (001_nc.cpp)
// Rule: MISRA C++ 8-0-1 — each declaration shall declare no more than one
// declarator. This file intentionally violates 8-0-1 in several spots.
// Marked with // NC for clarity.
#include <iostream>
#include <iomanip>
#include <array>
#include <cstddef>
namespace alt_001 {
    struct State { float alt; float vel; }; // OK: members are separate
    static float clamp(float v, float lo, float hi){ return v < lo ? lo : (v > hi ? hi : v); }
    void step(){
        float error=0.0F, integral=0.0F;        // NC (two declarators)
        double kp=1.10, ki=0.05;                // NC (two declarators)
        int samples=0, drops=0;                 // NC (two declarators)
        State s{0.0F, 0.0F};                    // OK (aggregate init)
        const float dt=0.02F;
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
