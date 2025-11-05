// Context: Navigation waypoint distance

// Seed 017 — C: variables without underscore prefix
#include <iostream>
int main(){
    double x1=0.0, y1=0.0, x2=100.0, y2=100.0; // C
    double dist = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
    std::cout << "dist_sq=" << dist << "\n";
    return 0;
}