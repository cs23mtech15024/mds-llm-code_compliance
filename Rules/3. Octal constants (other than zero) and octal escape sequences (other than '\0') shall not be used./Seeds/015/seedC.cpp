// Context: Medical ventilator airflow regulator

#include <iostream>
int main(){
    int valveOpen = 16; // C: decimal equivalent of 020
    int pressure = 8;   // C: decimal equivalent of 010
    std::cout<<"Valve="<<valveOpen<<", Pressure="<<pressure<<std::endl;
    return 0;
}
