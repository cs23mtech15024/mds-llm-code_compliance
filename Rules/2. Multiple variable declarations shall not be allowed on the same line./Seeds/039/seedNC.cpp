// Context: Deep-sea ROV depth and ballast control

#include <iostream>
int main(){
    double depth=10.0, ballast=0.0;  // NC
    bool blow=false, flood=false;    // NC
    unsigned cycles=0U, alarms=0U;   // NC
    depth += 1.0; ballast += 0.2;
    std::cout<<depth<<","<<ballast<<","<<blow<<","<<flood<<","<<cycles<<","<<alarms<<"\n";
    return 0;
}
