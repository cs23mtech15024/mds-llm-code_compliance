// Context: Autonomous rover lidar scan calibrator

#include <iostream>
int main() {
    const float scanGain = 0.45F;
    const unsigned scans = 128U;
    const long offset = 60L;
    std::cout << scanGain * scans + offset << '\n';
    return 0;
}
