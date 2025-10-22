// Context: Wind farm wake interaction analyzer

#include <iostream>
int main(){
    double v1=9.0, v2=8.5;           // NC
    float kd=0.05F, ct=0.8F;         // NC
    int rows=2, cols=3;              // NC
    v2 -= 0.2; ct -= 0.01F;
    std::cout<<v1<<","<<v2<<","<<kd<<","<<ct<<","<<rows<<","<<cols<<"\n";
    return 0;
}
