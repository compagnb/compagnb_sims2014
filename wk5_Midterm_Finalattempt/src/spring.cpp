//
//  spring.cpp
//  wk5_Midterm_Finalattempt
//
//  Created by compagnb on 10/7/14.
//
//

#include "spring.h"

void spring:: init(particle *a, particle *b, float = .2){
    rest_length = (b->pos - a->pos).length();
    
}

void spring:: update() {
    ofVec3f dir = b->pos - a->pos;
    float dist = dir.length();
    if(dist == 0.0){
        dist = 0.0001; // prevent the division by 0
    }
    float f = (rest_length - dist) * k; // linear force spring
    dir.normalize();
    a->addForce(dir * -f);
    b->addForce(dir *f);
}