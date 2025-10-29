// Context: Medical ventilator airflow regulator

#include <iostream>
int main(){
    int valveOpen = 020; // NC: octal constant 020 = 16 decimal
    int pressure = 010;  // NC: octal constant 010 = 8 decimal
    std::cout<<"Valve="<<valveOpen<<", Pressure="<<pressure<<std::endl;
    return 0;
}
