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
    
    radius = _dist;
    angle = _intAngle;
    
}

//------------------------------------------------------------------------------------
void ball::update(float _step, ofPoint  _center){
    angle += _step;
    
    
    float xorig = ofGetWidth()*0.5;
	float yorig = ofGetHeight()*0.5;
    
    x = xorig + radius * cos(angle*0.5);
    y = yorig + radius * cos(angle);
    //    x = _center.x + radius * cos(angle);
    //    y = _center.y + radius * sin(angle);
    
    tail.push_back(*this);
    
    if(tail.size()>10){
        //tail.erase(tail.begin());
    }
}


//------------------------------------------------------------------------------------
void ball::draw(){
    ofSetColor(color.r, color.g, color.b, alpha);
    
    ofPushStyle();
    ofNoFill();
    ofBeginShape();
    
    //    for (int i = 0; i < tail.size(); i++) {
    //        ofVertex(tail[i]);
    //    }
    //
    //    for (ofPoint it: tail) {
    //        ofVertex(it);
    //    }
    
    for (auto &it: tail) {
        ofVertex(it);
    }
    
    ofEndShape(false);
    ofPopStyle();
    
    ofCircle(x, y,size);
}

