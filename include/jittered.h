#pragma once

#include "sampler.h"

class Jittered : public Sampler{
    public:
        Jittered(int samples = 1, int sets = 1);
    private:
        void gen_samples() override;
};
