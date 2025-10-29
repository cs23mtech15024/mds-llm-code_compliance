// Context: Wind farm wake interaction analyzer

#include <iostream>
int main(){
    double v1=9.0;        // C
    double v2=8.5;        // C
    float kd=0.05F;       // C
    float ct=0.8F;        // C
    int rows=2;           // C
    int cols=3;           // C
    v2 -= 0.2; ct -= 0.01F;
    std::cout<<v1<<","<<v2<<","<<kd<<","<<ct<<","<<rows<<","<<cols<<"\n";
    return 0;
}
