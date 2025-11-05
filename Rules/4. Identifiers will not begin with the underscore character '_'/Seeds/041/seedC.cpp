// Context: Distance measurement filter

// Seed 041 — C: function without underscore prefix
#include <iostream>
float apply_filter(float raw, float alpha) { // C
    return raw * alpha;
}
int main(){
    std::cout << "filtered=" << apply_filter(150.5F, 0.8F) << "\n";
    return 0;
}