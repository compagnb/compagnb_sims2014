//
//  spring.h
//  wk5_Midterm_Finalattempt
//
//  Created by compagnb on 10/7/14.
//
//

#pragma once

#include "ofMain.h"
#include "particle.h"


class spring{
public:
    particle *a, *b;
    float k;
    float rest_length;
    
    void init(particle *a, particle *b, float k);
    
    void update();
    
};