//
//
//  Wk2_SinCosNatural
//
//  Created by compagnb on 9/9/14.
//
//

#pragma once

#include "ofMain.h"

class ball : public ofPoint {
public:
    
    //sets the distance and angle
    void set(float _dist, float _intAngle);
    
    //moves... i am not using the of point here
    void update(float _step, ofPoint _center);
    
    //draws stuff
    void draw();
    
    float radius;
    float angle;
    float size;
    
    //vector for tail
    vector< ofPoint > tail;
    
    //color and alpha
    ofColor color;
    int alpha;
    
};

