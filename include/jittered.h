#pragma once

#include "sampler.h"

class Jittered : public Sampler{
    public:
        Jittered(int samples = 1, int sets = 40);
    private:
        virtual void gen_samples();
};
