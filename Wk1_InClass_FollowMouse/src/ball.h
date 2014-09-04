//
//
// wk1_InClass_FollowMouse
//
//  Created by compagnb on 8/28/14.
//
//

#pragma once
#include "ofMain.h"

class ball {// making the class dont forget the semi colin
    
public:// variables that any other part can access
    
    ball();//constructor - replaces set up... called upon when a new particle is created
    
    //function initialization
    void update();
    void draw();
    
    //variable initialization
    int rad, posX, posY, speedX, speedY, colorR, colorG, colorB;
    
    bool collide;
    
private: // variables that can only be accessed within this class
};