//
//
//  Wk2_SquareTailTrails
//
//  Created by compagnb on 9/9/14.
//
//

#include "ball.h"

//------------------------------------------------------------------------------------

void ball::set(float _dist, float _intAngle){
    
    //set the radious = to distance
    radius = _dist;
    //and the angle = intAngle
    angle = _intAngle;
    
}

//------------------------------------------------------------------------------------
void ball::update(float _step, ofPoint  _center){
    //i am bypassing the ofPoint Center
    
    //angle plus step
    angle += _step;
    
    //set it to center
    float xorig = ofGetWidth()*0.5;
	float yorig = ofGetHeight()*0.5;
    
    //making shit move
    x = xorig + radius * cos(angle*0.5);
    y = yorig + radius * cos(angle);
  
    //push info back into vector
    tail.push_back(*this);
}


//------------------------------------------------------------------------------------
void ball::draw(){
    
    //set color
    ofSetColor(color.r, color.g, color.b, alpha);
    
    ofPushStyle();
    //no fill or else it runs to slow...
    //ofSetColor(color.r, color.g, color.b, 5);
    ofNoFill();
    ofBeginShape();
    
    // apply it to the tail
    for (auto &it: tail) {
        ofVertex(it);
    }
    //or written out the long way
    //    for (int i = 0; i < tail.size(); i++) {
    //        ofVertex(tail[i]);
    //    }
    //
    //    for (ofPoint it: tail) {
    //        ofVertex(it);
    //    }
    
    ofEndShape(false); //let it keep going
    ofPopStyle();
    
    //draw the circle!
    ofCircle(x, y,size);
}

