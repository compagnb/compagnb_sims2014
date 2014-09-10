//
// 
//  Wk2_Atan2Xeno
//
//  Created by compagnb on 9/10/14.
//
//

#pragma once

#include "ofMain.h"

class ball {
public:
    
    ball();//contructor replaces setup
    
    void	draw();//stuff is drawn
    void	xenoToPoint(float catchX, float catchY);//catch my mouse!
    
    ofPoint		pos;
    ofPoint		prevPos;
    
    float angle;
    float size;
    float catchUpSpeed;
    float pct;
    float sinOfTime;
    float sinOfTimeMapped;
    
    //vector for tail
    vector< ofPoint > tail;
    
    //color and alpha
    ofColor color;
    int alpha;
    
};

