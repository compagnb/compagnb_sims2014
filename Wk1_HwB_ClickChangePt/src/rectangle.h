//
//
//  Wk1_HwB_ClickChangePt
//
//  Created by compagnb on 8/31/14.
//
//

#pragma once

#include "ofMain.h"

class rectangle {//declare class and name
    public: //publicly visible variables and functions
    
        rectangle(); //constructor - takes the place of setup
    
        //functions
        void draw(); //what we draw in the screen
        void interpolateByPct (float myPct); // the movement of our shape

        //variables
        ofPoint pos; //the x and y positions of the shape
        ofPoint posa; //the beginning x and y positions of the shape
        ofPoint posb; //the end x and y positions of the shape

        float pct; // the percentage we are between points a and b

    private:
    
};