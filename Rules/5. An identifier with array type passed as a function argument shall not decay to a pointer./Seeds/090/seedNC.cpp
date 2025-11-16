// Context: Laser cutting path coordinates

// Seed 090 — NC: path coordinates decay to pointer
#include <iostream>
void execute_cut_path(float coords[]) { // NC
    std::cout << "x0=" << coords[0] << "\n";
}
int main(){
    float cut_path[1000] = {10.5F};
    execute_cut_path(cut_path);
    return 0;
}