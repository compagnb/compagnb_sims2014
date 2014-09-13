//
//  
//  Wk3_HW_Fireworks
//
//  Created by compagnb on 9/13/14.
//
//

#pragma once

#include "ofMain.h"

class tail{
    public: //everyone can see this stuff
    
    void setup();
        void update(float x, float y);
        void draw();
        void clearPoints();
    
        vector <ofPoint>points;
        ofPoint temp;
    
        float tailCount;
    
};