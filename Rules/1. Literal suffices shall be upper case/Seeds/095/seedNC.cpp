// Context: Autonomous rover lidar scan calibrator

#include <iostream>
int main() {
    const float scanGain = 0.45f;
    const unsigned scans = 128u;
    const long offset = 60l;
    std::cout << scanGain * scans + offset << '\n';
    return 0;
}
