#include "spring.h"

//---------------------------------------------------------------------
spring::spring(){
    particleA = NULL;
    particleB = NULL;
    k = 0.05;
}

spring::spring(particle *_A, particle *_B, float _springiness){
    particleA = _A;
    particleB = _B;
    k = _springiness;
    restlength = (_A->pos.distance(_B->pos));
}

//---------------------------------------------------------------------
void spring::update(){
    if ((particleA == NULL) || (particleB == NULL)){
        return;
    }
    
    ofVec3f force = particleA->pos - particleB->pos;  // the direction
    float len = force.length();
    float stretchLength = len - restlength;
    
    force.normalize();
    force *= k * stretchLength;
    
    particleA->addForce(-force*0.5);
    particleB->addForce(force*0.5);
}


//---------------------------------------------------------------------
void spring::draw(){
    
    if ((particleA == NULL) || (particleB == NULL)){
        return;
    }
    
    ofLine(particleA->pos, particleB->pos);
}