//
//
//  Wk1_HwBonus_MultipleXenoTrail
//
//  Created by compagnb on 9/2/14.
//
//

#pragma once

#include "ofMain.h"

class ball{ // declare and name the class

    public: // all the variables that everyone can see

        ball(); //constructor - replaces setup

        void draw(); //where we draw stuff
        void xenoToPoint(float catchX, float catchY); //what makes stuff move

        //variables
        ofPoint pos; //where the x and y are
    
        ofColor color; //what the color is
    
        int alpha, rad; //alpha channel

        float catchUpSpeed; //take the percentage of where I want to be, and 1-catchUpSpeed of my position
    
    private:
    
};
