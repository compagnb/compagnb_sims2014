//
//  particle.h
//  wk5_Midterm_Finalattempt
//
//  Created by compagnb on 10/7/14.
//
//

#pragma once

#include "ofMain.h"

class particle{
public:
    
    ofVec3f pos,vel,forces;
    float mass, inverseMass, drag;
    
    void init(ofVec3f pos, float mass, float drag);
    void update();
    void addForce(ofVec3f oForce);
    
};
