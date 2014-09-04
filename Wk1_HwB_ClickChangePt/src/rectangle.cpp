//
//
//  Wk1_HwB_ClickChangePt
//
//  Created by compagnb on 8/31/14.
//
//

#include "rectangle.h"

//------------------------------------------------------------------
rectangle::rectangle(){
    
}

//------------------------------------------------------------------
void rectangle::draw(){
    
    //fill shape
    ofFill();
    
    //change mode to center
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    //change color to teal at 70% alpha
    ofSetColor (0, 255, 255, 70);
    
    //draw rectangle
    ofRect(pos.x, pos.y, 40, 40);
    
    
}

//------------------------------------------------------------------
void rectangle::interpolateByPct(float myPct){
    
    pct = myPct;
    pos.x = (1-pct) * posa.x + (pct) * posb.x;
    pos.y = (1-pct) * posa.y + (pct) * posb.y;
    
    // this is an alternative way to write above..
	// differe style, but the same mathematically.
	//pos.x = posa.x + (pct) * (posb.x-posa.x);
    
}

//------------------------------------------------------------------
