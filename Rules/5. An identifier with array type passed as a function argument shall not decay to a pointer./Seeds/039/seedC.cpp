// Context: Timer capture register values

// Seed 039 — C: capture values by reference
#include <iostream>
#include <cstdint>
std::uint32_t get_capture_time(std::uint32_t (&captures)[4]) { // C
    return captures[0];
}
int main(){
    std::uint32_t timer_captures[4] = {12345};
    std::cout << "capture0=" << get_capture_time(timer_captures) << "\n";
    return 0;
}