//
//  spring.h
//  Wk5_WaterMidterm
//
//  Created by compagnb on 10/4/14.
//
//

#pragma once
#include "ofMain.h"

class spring {
public:
    
    void init(float _xpos, float _height, float _targetHeight, float _speed);
    void update(float _damp, float _k);
    void display();
    
    float xpos;
    ofPoint vel;
    
    float speed;
    float height;
    float targetHeight;
    
};