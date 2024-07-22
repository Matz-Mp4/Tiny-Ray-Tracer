#pragma once

#include "sampler.h"

class ViewPlane {
    public:
        int length;  
        int height; 
        float pixel_size;
        float gamma;      // monitor gamma factor  
        float inv_gamma;  // one over gamma
        Sampler* sampler_ptr;

        ViewPlane();
       ~ViewPlane();
        ViewPlane(const int length, const int height, const float pixe_size, const float gamma, Sampler* sp);
          
        ViewPlane with_len(const int length);
        ViewPlane with_height(const int height);
        ViewPlane with_psize(const float pixel_size);
        ViewPlane with_gamma(const float gamma);
        void with_sampler(Sampler* sp);
        ViewPlane with_samples(const int samples);

        int n_samples();
};
