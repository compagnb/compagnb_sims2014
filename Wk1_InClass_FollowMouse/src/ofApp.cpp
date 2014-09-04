//
//
// wk1_InClass_FollowMouse
//
//  Created by compagnb on 8/28/14.
//
//

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // Smooth edges
    ofEnableSmoothing();
    
    // Fixed framerate
    ofSetFrameRate(30);
    
    // Initial x position of the ball
    myBall.posX = ofGetWindowWidth()*0.5;
    
    // Initial y position of the ball
    myBall.posY = ofGetWindowHeight()*0.5;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    myBall.posX += ( mouseX - myBall.posX  )*0.1;
    myBall.posY += ( mouseY - myBall.posY )*0.1;
    
    //    ofDist(myBall.posX, myBall.posY, mouseX, myY);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //    myBall.posX = mouseX;
    //    myBall.posY = mouseY;
    myBall.rad = ofRandom(10, 100);
    
    myBall.draw();
    
    //    //find the readings of the mouse
    //    myX = mouseX;
    //    myY = mouseY;
    
    //    //ball on mouse
    //    ofSetColor(200, 0, 200, 50);
    //    ofFill();
    //    ofCircle(myX, myY,10);
    //    ofSetColor(255);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
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