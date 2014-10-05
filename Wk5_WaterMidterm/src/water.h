//
//  water.h
//  Wk5_WaterMidterm
//
//  Created by compagnb on 10/4/14.
//
//

#pragma once
#include "ofMain.h"
#include "spring.h"

class water {
    public:
    
    void init();
    void update();
    void draw();
    void splash(float index, float speed);
    
    ofPoint mouse;
    
    vector <spring> springs;
    
    int waterCols;
    float k = 0.025f;
    float damp = 0.025f;
    float spread = 0.025f;//controls how fast the waves spread
    
    ofVbo vbo;
    
    
};