#pragma once

#include "ofMain.h"

class Particle {
public:
    Particle();
    
     void setInit(ofPoint _pos, ofPoint _vel = ofPoint(0,0));
    
    void addForce(ofPoint _force);
    
    void addRepulsionForce(ofPoint _pos, float _rad, float _scale);
    void addAttractionForce(ofPoint _pos, float _rad, float _scale);
    void addClockwiseForce( ofPoint _pos, float _rad, float _scale);
    void addCounterClockwiseForce( ofPoint _pos, float _rad, float _scale);
    void setColorCondition(int red, int green, int blue);
    void bounceOffWalls();
    
    void seek( ofPoint dest );
    
    void update();
    void draw();
    
    ofColor color;
    
    ofPoint pos;
    ofPoint vel;
    ofPoint acc;
    ofPoint size;
    
    float radius;
    float damp;
    
    ofPoint squash;
    ofPoint stretch;
    
    
private:
   
};