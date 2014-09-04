//
//
//  Wk1_HwC_ShaperControls
//
//  Created by compagnb on 9/1/14.
//
//

#pragma once

#include "ofMain.h"

class rectangle{ //define and name class
    public: //variables that can be seen by everyone
    
        rectangle(); //constructor takes the place of setup
    
        void draw(); //where we draw stuff in the screen
        void interpolateByPct(float myPct); //where the movment happens
    
        //variables
        ofPoint pos; //x and y positions
        ofPoint posa; //beginning x and y positions
        ofPoint posb; //end x and y positions
    
        ofColor color; //color
        ofColor colora; //beginning colors
        ofColor colorb; //ending colors
    
        int alpha, alphaa, alphab;
    
        ofPoint size; // size length and width
        ofPoint sizea; //start size
        ofPoint sizeb; //end size
    
        float pct, shaper; //percentage we are between points a and b
    
    private:
    
    
};
