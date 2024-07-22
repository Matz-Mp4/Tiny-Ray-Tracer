#include "../../include/multijittered.h"
#include "../../include/math.h"
#include <cmath>

MultiJittered::MultiJittered(int samples, int sets) :
    Sampler(samples, sets) {
    gen_samples();
}

void MultiJittered::gen_samples() {
    //TODO     
}
