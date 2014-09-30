//
//
//  Wk4_Hw_PathFollow
//
//  Created by compagnb on 9/27/14.
//  based on http://www.shiffman.net/teaching/nature/path-following/OM,
//
//

#pragma once

#include "ofMain.h"

class path{
    public:
    
    vector <ofVec2f> points;
    float rad;
    
    void init();
    void addPoint(float x, float y);
    void draw();
    
};