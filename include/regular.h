#pragma once

#include "sampler.h"

class Regular: public Sampler{
    public:
        Regular(int samples = 1, int sets = 40);
    private:
        void gen_samples() override;
};
