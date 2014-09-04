//
//
//  Wk1_HwD_MulipleXeno
//
//  Created by compagnb on 9/1/14.
//
//

#pragma once

#include "ofMain.h"

class ball{ //declare and name the class
    
    public: // variables everyone can see
    
        ball(); //constructor - replaces setup
    
        void draw(); // where we draw our stuff
        void xenoToPoint(float catchX, float catchY); //what makes stuff move
    
        //variables
        ofPoint pos; //where the x and y are
    
        ofColor color; // what color it is
    
        int alpha; // alpha channel
    
        float		catchUpSpeed;		// take this pct of where I want to be, and 1-catchUpSpeed of my pos
    
    private:
    
};
