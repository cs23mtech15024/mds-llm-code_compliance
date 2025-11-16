// Context: ADC sampling rate configurations

// Seed 032 — C: ADC config array by reference
#include <iostream>
void configure_adc(int (&sample_rates)[8]) { // C
    sample_rates[0] = 1000;
    std::cout << "adc0_rate=" << sample_rates[0] << "\n";
}
int main(){
    int adc_rates[8] = {0};
    configure_adc(adc_rates);
    return 0;
}