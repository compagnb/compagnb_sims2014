//
//
//  Wk3_HW_Fireworks
//
//  Created by compagnb on 9/13/14.
//
//

#pragma once

#include "ofMain.h"
#include "tail.h"

class particle {
    public://shit everyone can see
    
        particle(); //constructor - takes the place of setup
    
    
        //functions
        void addForce(float x, float y); //adds movement i.e a push
        void resetForce(); //resets force
    
        void addDampingForce(); //adds resistance, i.e. gravity
    
        void setInitCondition(float posX, float posY, float velX, float velY); //setting initial points for position and velocity
    
        void setColorCondition(int red, int green, int blue);
    
        void update(); //where things update
        void draw(); //where we draw stuff
        void reset(); //reset everything

        //variables
    
        ofVec2f pos; //position
        ofVec2f vel; //velocity
        ofVec2f frc; //acceleration

        ofColor color;
        int alpha;
        float damping;
    
        tail myTail;
    
    private://stuff only the particle can see
    
    
    
};
