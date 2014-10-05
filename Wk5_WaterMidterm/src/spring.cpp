//
//  spring.cpp
//  Wk5_WaterMidterm
//
//  Created by compagnb on 10/4/14.
//
//

#include "spring.h"

void spring::init(float _xpos, float _height, float _targetHeight, float _speed) {
    xpos = _xpos;
    speed = _speed;
    height = _targetHeight;
    targetHeight = _height;
}

void spring::update(float _damp, float _k) {
    
    float x = targetHeight - height;
    speed += _k * x - speed * _damp;
    height += speed;
}

void spring::display() {
    
}