//
//  rock.h
//  Wk5_WaterMidterm
//
//  Created by compagnb on 10/4/14.
//
//

#pragma once
#include "ofMain.h"
#include "water.h"

class rock {
    public:
        rock();
        void update();
        void draw();
    
        ofPoint pos; // position
        ofPoint vel; // speed
        ofPoint acc; // gravity
        int rad;
    
        //more advanced
        //void update(water _water);
        //void draw(SpriteBatch spriteBatch, Texture2D texture)
        //water water;
    
    
};
