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
    
    void set(float _dist, float _intAngle);
    
    void update(float _step, ofPoint _center);
    
    void draw();
    
    float radius;
    float angle;
    float size;
    
    vector< ofPoint > tail;
    
    ofColor color;
    int alpha;
    
};

