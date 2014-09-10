//
//
//  Wk2_SquareTailTrails
//
//  Created by compagnb on 9/9/14.
//
//

#pragma once

#include "ofMain.h"

class rectangle : public ofPoint {
    public: // the stuff that everyone can see and access
    
    void set(float _dist, float _intAngle); // sets the distance and the angle
    
    void update(float _step, ofPoint _center); // sets the step you want it to take
    
    void draw(); //draws the object
    
    float radius;
    float angle;
    float size; //size of the square
    
    vector< ofPoint > tail; //tail of object in a vector
    
};
    
