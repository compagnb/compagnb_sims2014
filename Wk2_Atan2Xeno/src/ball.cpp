//
//
//  Wk2_Atan2Xeno
//
//  Created by compagnb on 9/10/14.
//
//


#include "ball.h"

//------------------------------------------------------------------------------------

ball::ball(){
    ofEnableAlphaBlending();
    
	catchUpSpeed = 0.3f;
	
	pos.set(0,0);
	prevPos.set(0,0);
    
    
}



//------------------------------------------------------------------------------------
void ball::draw(){
    
    ofFill();
	
	//ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
   
    sinOfTime = sin( ofGetElapsedTimef()*1.5);
    
	//set color
    ofSetColor(color.r, color.g, color.b, alpha);
    
	ofPushMatrix();
    ofTranslate(pos.x, pos.y, 0);
    ofRotateZ(angle * RAD_TO_DEG);
    
        ofLine(10,20,150+sinOfTimeMapped,150-sinOfTimeMapped);
        ofLine(20,30,150-sinOfTimeMapped,150+sinOfTimeMapped);
        ofLine(30,40,100+sinOfTimeMapped,100-sinOfTimeMapped);
        ofLine(50,60,100-sinOfTimeMapped,100+sinOfTimeMapped);
        ofLine(60,70,50+sinOfTimeMapped,50-sinOfTimeMapped);
        ofLine(80,90,50-sinOfTimeMapped,50+sinOfTimeMapped);
        ofBezier(-5, -10, 10, 5, 20, 15, 40, angle+10);
        ofBezier(-10, -5, 5, 10, 15, 20, angle+10, 40);
    
    ofPopMatrix();
    
    //draw the circle!
    ofCircle(pos.x, pos.y,size);
    
    
//    ofPushStyle();
//    //no fill or else it runs to slow...
//    //ofSetColor(color.r, color.g, color.b, 5);
//    ofNoFill();
//    ofBeginShape();
//    
//    // apply it to the tail
//    for (auto &it: tail) {
//        ofVertex(it);
//    }
//    ////
//    ofEndShape(false); //let it keep going
//    ofPopStyle();
    
    
}

//------------------------------------------------------------------------------------
void ball::xenoToPoint(float catchX, float catchY){
	
	pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
	pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
    
	float dx = pos.x - prevPos.x;
	float dy = pos.y - prevPos.y;
	
	angle = atan2(dy, dx) + (2*PI)/3;
    
	prevPos.x = pos.x;
	prevPos.y = pos.y;
	
    
}


