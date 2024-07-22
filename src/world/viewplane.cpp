#include "../../include/view_plane.h"
#include "../../include/jittered.h"
#include "../../include/regular.h"
#include <iostream>


ViewPlane::ViewPlane():
    length(800),
    height(800),
    pixel_size(1.0),
    gamma(1.0),
    inv_gamma(1.0),
    sampler_ptr(nullptr)
{}


ViewPlane::ViewPlane(const int length, const int height, const float pixel_size, const float gamma, Sampler* sp):
    length(length),
    height(height),
    pixel_size(pixel_size),
    gamma(gamma),
    inv_gamma(1.0 / gamma),
    sampler_ptr(sp)
{}

ViewPlane::~ViewPlane() {
	if(sampler_ptr){
		delete sampler_ptr;
		sampler_ptr = nullptr;
	}
}


 

ViewPlane ViewPlane::with_len(const int length){
    return ViewPlane(length, 
                     this->height, 
                     this->pixel_size, 
                     this->gamma,
                     this->sampler_ptr);
}

ViewPlane ViewPlane::with_height(const int height){
    return ViewPlane(this->length, 
                     height, 
                     this->pixel_size, 
                     this->gamma,
                     this->sampler_ptr);
}


ViewPlane ViewPlane::with_psize(const float pixel_size){
    return ViewPlane(this->length, 
                     this->height, 
                     pixel_size, 
                     this->gamma,
                     this->sampler_ptr);
}


ViewPlane ViewPlane::with_gamma(const float gamma){
    return ViewPlane(this->length, 
                     this->height, 
                     this->pixel_size, 
                     gamma,
                     this->sampler_ptr);
}


void ViewPlane::with_sampler(Sampler* sp){

    if(sampler_ptr) {
        delete sampler_ptr;
        sampler_ptr = nullptr;
    }
    this->sampler_ptr = sp;

}
/*
ViewPlane ViewPlane::with_samples(const int samples){
    if(samples > 1) return with_sampler(new Jittered(samples));
    else return with_sampler(new Regular(samples));
}*/

int ViewPlane::n_samples(){
    return sampler_ptr->get_num_samples();
}
