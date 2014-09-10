//
//
//  Wk2_SquareTailTrails
//
//  Created by compagnb on 9/9/14.
//
//

#include "rectangle.h"

//------------------------------------------------------------------------------------

void rectangle::set(float _dist, float _intAngle){
    
    //setting up the angle and distance of the movement
    radius = _dist;
    angle = _intAngle;
    
}

//------------------------------------------------------------------------------------
void rectangle::update(float _step, ofPoint  _center){
    
    //adding to the angle to make it orbit
    angle += _step;
    
    //start is at the middle of the screen
    float xorig = ofGetWidth()*0.5;
	float yorig = ofGetHeight()*0.5;
   
    //actually moving
    x = xorig + radius * cos(angle);
    y = yorig + radius * sin(angle);
    
    //push data back in the vector tail
    tail.push_back(*this);
    
    
    if(tail.size()>100){
        //erase after 100
        //tail.erase(tail.begin());
    }
}


//------------------------------------------------------------------------------------
void rectangle::draw(){
    //set color of object
    ofSetColor(200, 0, 200);
    
    ofPushStyle();
    //change color
    ofSetColor(200,0,200,10);
    ofBeginShape();
    
    //apply to tail size
    for (auto &it: tail) {
        ofVertex(it);
    }
    // This can also be written like this...
    //    for (int i = 0; i < tail.size(); i++) {
    //        ofVertex(tail[i]);
    //    }
    //
    //    for (ofPoint it: tail) {
    //        ofVertex(it);
    //    }
    
    //dont end
    ofEndShape(false);
    ofPopStyle();
    
    //draw rectangle
    ofRect(x, y,size,size);
}