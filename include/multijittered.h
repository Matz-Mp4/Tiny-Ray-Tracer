#pragma once

#include "sampler.h"

class MultiJittered : public Sampler{
    public:
        MultiJittered(int samples = 1, int sets = 40);
    private:
        virtual void gen_samples();
};
