#include "../../include/jittered.h"
#include "../../include/math.h"
#include <cmath>

Jittered::Jittered(int samples, int sets) :
    Sampler(samples, sets) {
    gen_samples();
}

Jittered::~Jittered()	{}

void Jittered::gen_samples() {
    int n = static_cast<int>(sqrt(n_samples));

    for(int p = 0; p < n_sets; p++) 
        for(int j = 0; j < n_sets; j++) 
            for(int k = 0; k < n_sets; k++) {
                double data [] = {k + rand_float() / n,  j + rand_float() / n};
                Tuple<2> sp(data);
                samples.push_back(sp);
            }

     
}
