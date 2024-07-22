#include "../../include/sampler.h"
#include <algorithm>
#include <iostream>
#include <random>
#include "../../include/math.h"

Sampler::~Sampler(){
    samples.clear();
    shuffled_indices.clear();
}

Sampler::Sampler(int samples, int sets) :

    n_samples(samples),
    n_sets(sets),
    count(0),
    jump(0) 
{
    this->samples.reserve(n_samples * n_sets);
    setup__indices();

}
void Sampler::setup__indices() {
    shuffled_indices.reserve(n_samples * n_sets);
    std::vector<int> indices;
    
    for(int j = 0; j < n_samples; j++) {
        indices.push_back(j);
    }

    for(int p = 0; p < n_sets; p++) {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(indices.begin(), indices.end(), g);

        for(int j = 0; j < n_samples; j++) 
            shuffled_indices.push_back(indices[j]);
    }

}

Tuple<2> Sampler::sample_unit_square() {
    if(count % n_samples == 0) //start of a new pixel 
        jump = (rand_int() % n_sets) * n_samples; 

    return (samples[jump + shuffled_indices[jump + count++ % n_samples]]);
}

int Sampler::get_num_samples() {
    return this->n_samples;
}
