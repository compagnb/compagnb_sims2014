//
//  particle.cpp
//  wk5_Midterm_Finalattempt
//
//  Created by compagnb on 10/7/14.
//
//

#include "particle.h"

void particle::init(ofVec3f pos, float mass, float drag){
    if (mass == 0.0f){
        inverseMass = 0;
    }else if (mass < 0.001){
        mass = 0.001;
    }else if (mass!=0.0f){
        inverseMass = mass;
    }
}

void particle::update(){
    forces *= inverseMass;
    vel += forces;
    forces.set (0, 0, 0);
    vel.limit(15);
    pos += vel;
    vel *= drag;
}

void particle:: addForce(ofVec3f oForce) {
    forces += oForce;
}