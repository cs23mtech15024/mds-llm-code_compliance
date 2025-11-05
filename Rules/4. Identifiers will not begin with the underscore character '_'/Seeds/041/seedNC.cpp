// Context: Distance measurement filter

// Seed 041 — NC: function starts with underscore
#include <iostream>
float _apply_filter(float raw, float alpha) { // NC
    return raw * alpha;
}
int main(){
    std::cout << "filtered=" << _apply_filter(150.5F, 0.8F) << "\n";
    return 0;
}