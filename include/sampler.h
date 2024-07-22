#pragma once

#include "tuple.h"
#include <vector>

class Sampler {
    protected:
        int n_samples;                     //number of sample points
        int n_sets;                        //number of sample sets stored
        std::vector<Tuple<2>> samples;     //sample points on unit square
        std::vector<int> shuffled_indices; //shuffled samples array indices
        size_t count;                      //the current number of sample points used
        int jump;                          //random index jump

    public: 
        Sampler() = default;
        Sampler(int samples = 1, int sets = 40);
        virtual ~Sampler();

        virtual void gen_samples() = 0;      /*generate samples*/
        void         setup__indices();       /*setup randomly shaffled indices*/
        void         shuffle_samples();      /*randomly shuffled the smaples in each pattern */
        Tuple<2>     sample_unit_square();   /*get next sample on unit square*/
        int          get_num_samples();


};
