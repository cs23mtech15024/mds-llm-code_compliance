// Context: Navigation waypoint distance

// Seed 017 — NC: variables start with underscore
#include <iostream>
int main(){
    double _x1=0.0, _y1=0.0, _x2=100.0, _y2=100.0; // NC
    double dist = (_x2-_x1)*(_x2-_x1) + (_y2-_y1)*(_y2-_y1);
    std::cout << "dist_sq=" << dist << "\n";
    return 0;
}