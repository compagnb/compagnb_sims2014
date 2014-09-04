//
//
//  Wk1_HwC_ShaperControls
//
//  Created by compagnb on 9/1/14.
//
//

#include "rectangle.h"

//------------------------------------------------------------------
rectangle::rectangle(){
    shaper = 1;
    
}

//------------------------------------------------------------------
void rectangle::draw(){
    
    //fill shape
    ofFill();
    
    //set rect mode to center
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    //set color of rect to purple with a 70% alpha
    ofSetColor(200, 0, 200, alpha);
    //ofSetColor(color.r, color.g, color.b, color.a);
    
    //draw rect
    ofRect(pos.x, pos.y, size.x, size.y);
    
}

//------------------------------------------------------------------
void rectangle::interpolateByPct(float myPct){
    
    pct = powf(myPct, shaper);
    pos.x = (1-pct) * posa.x + (pct) * posb.x;
    pos.y = (1-pct) * posa.y + (pct) * posb.y;
    
    // this is an alternative way to write above..
	// differe style, but the same mathematically.
	//pos.x = posa.x + (pct) * (posb.x-posa.x);
    
    size.x = (1-pct) * sizea.x + (pct) * sizeb.x;
    size.y = (1-pct) * sizea.y + (pct) * sizeb.y;
    
    color.r = (1-pct) * colora.r + (pct) * colorb.r;
    color.g = (1-pct) * colora.g + (pct) * colorb.g;
    color.b = (1-pct) * colora.b + (pct) * colorb.b;
    alpha = (1-pct) * alphaa + (pct) * alphab;
    
}