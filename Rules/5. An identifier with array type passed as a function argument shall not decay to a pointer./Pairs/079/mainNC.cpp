// Context: Neural network layer weights

// ------ Non-Compliant Program (079_nc.cpp)
// Context: Neural network layer weights
// Rule: Array parameter decays to pointer (VIOLATION)
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace nn_079_nc {

static void init_first(float *w, std::size_t n){ if(n>0U) w[0] = 0.01F; }

void initialize_weights(float weights[]) { // NC API
    const std::size_t N = 784U; (void)N;
    init_first(weights, 784U);
    std::cout << std::fixed << std::setprecision(5)
              << "w0=" << weights[0] << "\n";
}

static void dump_head(const float *w){
    for(int i=0;i<5;i++){ std::cout << (i?",":"head:") << w[i]; }
    std::cout << "\n";
}

} // namespace nn_079_nc

int main(){
    using namespace nn_079_nc;
    float nn_weights[784] = {0.0F};
    initialize_weights(nn_weights);
    dump_head(nn_weights);
    return 0;
}
