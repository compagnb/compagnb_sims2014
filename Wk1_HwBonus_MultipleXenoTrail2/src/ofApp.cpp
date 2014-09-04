//
//
//  Wk1_HwBonus_MultipleXenoTrail
//
//  Created by compagnb on 9/2/14.
//
//

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //set framerate
    ofSetFrameRate(60);
    
    //macs by default run on non vertical sync, which make animations run very very fast. This fixes that
    ofSetVerticalSync(true);
    
    // for the alpha in the rectangle
    ofEnableAlphaBlending();
    
    //set background color to light grey
    ofBackground(200, 200, 200);
    
    // set the color of the balls
    for (int i=0; i < 99; i++){
        myBall[i].color.r = 1+i;
        myBall[i].color.g = 0;
        myBall[i].color.b = 2+i;
        myBall[i].alpha = i;
        myBall[i].rad = i;
        
        
        // set the position of the balls
        myBall[i].pos.x = ofGetWidth()/2;
        myBall[i].pos.y = ofGetHeight()/2;
        
        //    //catchUpSpeeds
        //
        //    myBall[i].catchUpSpeed = 0.08f;
        //
    }

    

}

//--------------------------------------------------------------

void ofApp::update(){
    
    // set the color of the balls
    myBall[0].xenoToPoint(mouseX, mouseY);
    
    for (int i=1; i < 99; i++){
        myBall[i].xenoToPoint(myBall[i-1].pos.x, myBall[i-1].pos.y);
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //draw balls
    for (int i=0; i < 99; i++){
        myBall[i].draw();
    }
    
}//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
